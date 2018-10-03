class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        int end = 1;
        while (reader->get(end) < target) {
            end *= 2;
        }
        
        int start = 0;
        int mid;
        //std::cout << "start: " << start << ", end: " << end << ", mid: " << mid << "\n"; 
        while(start + 1 < end) {
            mid = (start + end) / 2;
            std::cout << "mid: " << mid << "\n";
            int val = reader->get(mid);
            if(val < target) start = mid;
            else end = mid;
        }

        if(reader->get(start) == target) return start;
        if(reader->get(end) == target) return end;
        
        return -1;
    }
};