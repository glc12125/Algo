class Solution {
private:
    void dfs(const std::string& s, int index, int segmentNum, std::vector<int>& answer, std::vector<std::string>& results) {
        if(segmentNum < 0) return;
        int len = s.size();
        if(index >= len) {
            if(segmentNum == 0) {
                std::string ip(std::to_string(answer[0]));
                for(int i = 1; i < 4; ++i) {
                    ip += "." + std::to_string(answer[i]);
                }
                results.push_back(ip);
            }
            return;
        } else if(segmentNum == 0) return;

        for(int i = index; i < len; ++i) {
            int num = std::stoi(s.substr(index, i - index + 1));
            if( -1 < num && num < 256 && answer.size() < 4 ) {
                if(num == 0 && i - index + 1 > 1) continue; // multiple zeros
                if(num != 0 && s[index] == '0') continue; // leading zeros
                answer.push_back(num);
                dfs(s, i + 1, segmentNum - 1, answer, results);
                answer.pop_back();
            } else break;
        }

    }
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        std::vector<std::string> results;
        if(s.size() == 0) return results;
        std::vector<int> answer;
        dfs(s, 0, 4, answer, results);
        return results;
    }
};