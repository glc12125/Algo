// This DFS will time out
class Solution {
private:
    bool dfs(vector<int> nums) {
        int len = nums.size();
        if(len == 0) return true;
        if(len < 3) return false;

        vector<int>::iterator it = nums.begin();
        int conseqCount = 1;
        int last = *it;
        it = nums.erase(it);

        while(it != nums.end()) {
            if(*it == (last + 1)) {
                it = nums.erase(it);
                if(++conseqCount >= 3) {
                    if(dfs(nums)) return true;
                }
                ++last;
            } else {
                ++it;
            }
        }
        return false;
    }
public:
    /**
     * @param nums: a list of integers
     * @return: return a boolean
     */
    bool isPossible(vector<int> &nums) {
        return dfs(nums);
    }
};


/*
1. We use a hashmap called tails to record extra information, where tails[i] means the number of
   consecutive subsequences we've found so far, who are longer than 3 , and tailed by number i,
2. When we meet number i, try to put it to the tail of one of found subsequences tailed by i-1.
   No need to worry that we might have a better choice to consider i as a brand new head for
another subsequence, because we can always append the new subsequence to a previous one tailed by i-1.
3. If we can't, it will cost one i+1 and one i+2 later to generate a new sequence. We just pay
   that right now by decrease cnt[i+1] and cnt[i+2]. Some one may worry that we make use of the
   numbers we haven't scanned so far. But actually we've already kept track of the numbers
   remained by cnt. Just imaging we grab the numbers needed from the very end of the string, and
   mark them as "used". If there is no such number available to pay, cnt will tell us by checking
   cnt[i+1] cnt[i+2] is positive or not
*/
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a boolean
     */
    bool isPossible(vector<int> &nums) {
        unordered_map<int,int> cnt, tails;
        for(int &i : nums) cnt[i]++;
        for(int &i : nums){
            if(!cnt[i]) continue;
            cnt[i]--;
            if(tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }
};