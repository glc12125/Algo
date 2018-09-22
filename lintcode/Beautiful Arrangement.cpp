// Use backtracking
class Solution {
private:
    void btFind(std::vector<int>& visited, int index, int& result) {
        int size = visited.size();
        if(index > size - 1) ++result;
        
        for(int i = 1; i < size; ++i) {
            if(!visited[i] && (i % index == 0 || index % i == 0)) {
                visited[i] = 1;
                btFind(visited, index + 1, result);
                visited[i] = 0;
            }
        }
    }
public:
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
    int countArrangement(int N) {
        std::vector<int> visited(N+1, 0);
        
        int result = 0;
        btFind(visited, 1, result);
        return result;
    }
};