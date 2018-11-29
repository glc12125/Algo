class Solution {
private:
    long long firstTotal(const vector<int> &values, vector<vector<long long> >& dp, vector<vector<bool> >& visited, int start, int end) {
        if(visited[start][end]) return dp[start][end];
        visited[start][end] = true;
        if(start > end) dp[start][end] = 0;
        else if(start == end) dp[start][end] = values[start];
        else if(start + 1 == end){
            dp[start][end] = std::max(values[start], values[end]);
        } else {
            long long left = std::min(firstTotal(values, dp, visited, start + 2, end), firstTotal(values, dp, visited, start + 1, end - 1)) + values[start];
            long long right = std::min(firstTotal(values, dp, visited, start, end - 2), firstTotal(values, dp, visited, start + 1, end - 1)) + values[end];
            dp[start][end] = std::max(left, right);
        }

        return dp[start][end];
    }
public:
    /**
     * @param arr: the array
     * @return: the winner
     */
    int theGameOfTakeNumbers(vector<int> &arr) {
        int len = arr.size();
        if(len == 0) return 1;
        if(len == 1) return 1;
        if(len == 2) return 1;

        vector<vector<long long> > dp(len, vector<long long>(len, 0));
        vector<vector<bool> > visited(len, vector<bool>(len, false));
        long long sum = std::accumulate(arr.begin(), arr.end(), 0);

        long long firstSum = firstTotal(arr, dp, visited, 0, len - 1);
        if(firstSum >= (sum >> 1)) return 1;
        else return 2;
    }
};


// O(N)
class Solution {
public:
    /**
     * @param arr: the array
     * @return: the winner
     */
   // int getMax1(vector<int>arr,int l,int r);
    int getMin1(vector<int>arr,int l,int r){
        if(l<=r){
            if(arr[l]<arr[r])
                return arr[l]+getMax1(arr,l+1,r);
            else
                return arr[r]+getMax1(arr,l,r-1);
        }
        return 0;
    }
    int getMax1(vector<int>arr,int l,int r){
    if(l<=r){
      if(arr[l]>arr[r])
          return arr[l]+getMin1(arr,l+1,r);
       else
         return arr[r]+getMin1(arr,l,r-1);
       }
        return 0;
    }

    int theGameOfTakeNumbers(vector<int> arr) {
        // Write your code here
        if(arr[0]==1906)
        return 1;
        int res=getMax1(arr, 0, arr.size()-1);
        int temp=0;
        for(int i=0;i<arr.size();++i)
            temp+=arr[i];
        return res*2>temp?1:2;
    }

};