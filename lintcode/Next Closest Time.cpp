class Solution {
private:
    void dfs(const vector<int>& digits, string current, vector<string>& allTimes){
         if(current.size() == 5) {
             allTimes.push_back(current);
             return;
         }
         if(current.size() == 2) {
             current += ':';
         }

         int len = current.size();
         for(int i = 0; i < 4; ++i) {
             if(len == 0 && digits[i] > 2) {continue;}
             if(len == 1 && current[0] == '2' && digits[i] > 4) {continue;}
             if(len == 3 && digits[i] > 5) {continue;}
             dfs(digits, current + to_string(digits[i]), allTimes);
         }
    }

public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        vector<int> digits(4, 0);

        digits[0] = time.at(0) - '0';
        digits[1] = time.at(1) - '0';
        digits[2] = time.at(3) - '0';
        digits[3] = time.at(4) - '0';

        sort(digits.begin(), digits.end());

        vector<string> allTimes;

        dfs(digits, "", allTimes);

        int index = 0;

        for (int i = 0; i < allTimes.size(); i++) {
            if (allTimes[i] == time) {
                index = i;
            }
        }

        //下一个时间便是答案
        index = (index + 1) % allTimes.size();

        return allTimes[index];
    }
};