// BFS
class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        queue<int> q;
        q.push(n);

        int cnt = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len-- > 0) {
                auto curr = q.front();
                q.pop();
                if(curr == 1) return cnt;
                if(curr & 1) {
                    q.push(curr+1);
                    q.push(curr-1);
                } else q.push(curr>>1);
            }
            ++cnt;
        }
    }
};