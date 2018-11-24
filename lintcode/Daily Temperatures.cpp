class Solution {
public:
    /**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> s;
        int len = temperatures.size();
        vector<int> result(len, 0);
        for(int i = 0; i <= len; ++i) {
            int curr = (i == len ? INT_MAX : temperatures[i]);
            while(!s.empty() && temperatures[s.top()] < curr) {
                result[s.top()] = (curr == INT_MAX ? 0 : i - s.top());
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};