class Solution {
private:
    bool checkRange(const vector<int>& data, int start, int end) {
        int len = data.size();

        int header = 2; // 10xxxxxx
        for(int i = start + 1; i < end; ++i) {
            if(i >= len || (data[i] >> 6) != header) return false;
        }
        return true;
    }
public:
    /**
     * @param data: an array of integers
     * @return: whether it is a valid utf-8 encoding
     */
    bool validUtf8(vector<int> &data) {
        int len = data.size();
        int start = 0;
        int header11110 = 30;
        int header1110 = 14;
        int header110 = 6;
        int header0 = 0;
        while(start < len) {
            int headerPart = data[start];
            if((headerPart >> 3) == header11110 && checkRange(data, start, start + 4)) start += 4;
            else if((headerPart >> 4) == header1110 && checkRange(data, start, start + 3)) start += 3;
            else if((headerPart >> 5) == header110 && checkRange(data, start, start + 2)) start += 2;
            else if((headerPart >> 7) == header0) ++start;
            else return false;
        }
        return true;
    }
};