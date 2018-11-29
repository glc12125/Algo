class Solution {
private:
    void merge(int a, int b, vector<int>&uf, vector<int> &size){
        int x = find(a, uf);
        int y = find(b, uf);
        if(x ==y) return;
        uf[y] = x;
        size[x] += size[y];
        size[y] = 1;

    }
    int find(int index, vector<int> &uf){
        if(uf[index] == index){
            return index;
        } else return find(uf[index], uf);
    }
public:
    /**
     * @param mp: the board
     * @return: the max number of points we can remove
     */
    int getAns(vector<vector<int>> &mp) {
        int m = mp.size();
        if(m < 1) return 0;
        int n = mp[0].size();
        if(n < 1) return 0;
        vector<int> uf(m*n,0);
        vector<int> size(m*n, 1);
        for(int i = 0; i<m*n; ++i){
            uf[i] = i;
        }

        for(int i = 0; i<m; ++i){
            int first = -1;
            for(int j = 0; j<n; ++j){
                if(mp[i][j] == 1){
                    if(first==-1){
                        first = i*n+j;
                    } else {
                        merge(first, i*n+j, uf, size);
                    }
                }
            }
        }

        for(int j = 0; j<n; ++j){
            int first = -1;
            for(int i = 0; i<m; ++i){
                if(mp[i][j] == 1){
                    if(first == -1){
                        first = i*n+j;
                    } else {
                        merge(first, i*n+j, uf, size);
                    }
                }
            }
        }

        int res = 0;
        for(int c : size){
            res += (c-1);
        }
        return res;
    }
};