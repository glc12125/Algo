class Solution {
public:
    int balanceGraph(vector<vector<int>>& edges) {
        unordered_map< int , int > debt;
        for( int t = 0; t < edges.size(); t++){
            debt[edges[t][0]] -= edges[t][2];
            debt[edges[t][1]] += edges[t][2];
        }
        vector<int> account(debt.size(),0);
        int len = 0;
        for(auto v = debt.begin(); v != debt.end(); v++){         //keep only the unbalanced ones
            if((*v).second != 0){
                account[len++] = (*v).second;
            }
        }

        if(len == 0) return 0;

        vector<int> dp(1<<len,INT_MAX/2);

        for(int i = 1; i < 1 << len; i++){   // there are 2^len subsets

            int sum = 0, count = 0;
            for(int j = 0; j < len; j++){
                if((1<<j & i) != 0){         //if we choose node j in the subset
                    sum += account[j];       //accumulate the nodes degrees
                    count++;                 //increase the number of modifications
                }
            }

            if(sum == 0){                    //If the we can balance the degrees, then we have a sub problem, hence DP
                dp[i] = count - 1;           //for subset i, the maximum modifications
                for(int j = 1; j < i; j++){  //enumerate through the sub problem of the solvable subset
                    if(((i & j) == j) && dp[j] + dp[i-j] < dp[i]){
                        dp[i] = dp[j] + dp[i - j];  //get the smaller modification number if the subset exist
                    }
                }
            }

        }

        return dp[(1 << len) - 1];
    }
};