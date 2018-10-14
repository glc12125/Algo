class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        int len = s.size();
        if(len == 0) return 0;
        int dictLen = dict.size();
        if(dictLen == 0) return len;

        std::queue<std::string> q;
        q.push(s);
        std::unordered_set<std::string> checked;
        checked.insert(s);
        int minLen = s.size();
        while(!q.empty()) {
            auto source = q.front();
            q.pop();
            minLen = std::min(minLen, (int)source.size());
            for(auto target : dict) {
                int startPos = 0;
                std::size_t found = source.find(target, startPos);
                while(found != std::string::npos) {
                    auto newSource = source.substr(0, found) + source.substr(found + target.size());
                    if(checked.count(newSource) == 0) {
                        q.push(newSource);
                        checked.insert(newSource);
                    }
                    startPos = found + target.size();
                    found = source.find(target, startPos);
                }
            }
        }
        return minLen;
    }
};