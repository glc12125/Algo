class Solution {
public:
    /**
     * @param time:
     * @return: return a string represents time
     */
    string lastTime(string &time) {
        if(time.size() != 5) return "-1";
        auto pos = time.find(':');
        if(pos == string::npos) return "-1";

        int hour = stoi(time.substr(0, pos));
        int minute = stoi(time.substr(pos + 1));
        if(hour < 0 || hour > 24) return "-1";
        if(minute < 0 || minute > 59) return "-1";

        int value = hour * 60 + minute;
        //std::cout << value;
        vector<int> v = {600, 60, 10, 1};
        string res ="0000";

        for (int i = 1; i <= 1440; i++){

            int next = value - i;
            if(next < 0) {next = 23 * 60 + 59;}
            int d;
            unordered_set<char> numbers;
            for (d = 0; d < 4; d++){
                res[d] = '0' + next / v[d];
                next = next % v[d];

                if (numbers.count(res[d]))
                    break;
                numbers.insert(res[d]);
            }

            if (d == 4)
                break;
        }

        return res.substr(0,2) +":" + res.substr(2);
    }
};