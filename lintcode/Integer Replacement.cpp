// BFS
class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(n);
        visited.insert(n);

        int cnt = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len-- > 0) {
                auto curr = q.front();
                q.pop();
                if(curr == 1) return cnt;
                if(curr & 1) {
                    if(visited.count(curr + 1) == 0) q.push(curr+1);
                    if(visited.count(curr - 1) == 0) q.push(curr-1);
                } else {
                    if(visited.count(curr>>1) == 0) q.push(curr>>1);
                }
            }
            ++cnt;
        }
    }
};

// DFS
class Solution {
private:
    int dfs(int n, unordered_map<int, int>& mem) {
        if(mem.count(n)) return mem[n];
        if(n == 1) {
            mem[n] = 0;
        }
        else if(n&1) {
            mem[n] = std::min(dfs(n+1, mem), dfs(n-1,mem)) + 1;
        }
        else {
            mem[n] = dfs(n>>1, mem) + 1;
        }
        return mem[n];
    }
public:
    /**
     * @param n: a positive integer
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        unordered_map<int, int> mem;
        return dfs(n, mem);
    }
};

//
class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        int cnt = 0;
        while (n > 1){
            ++cnt;
            if (n % 2 == 0) n = n>>1;
            else if(n % 4 == 1 || n == 3) --n;
            else ++n;
        }
        return cnt;
    }
};