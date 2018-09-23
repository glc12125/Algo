class Solution {
private:
    int countTab(const std::string& str)
    {
        int res = 0;
        for (int i = 0; i < str.size(); i+=2)
        {
            if (str[i] == '\\' && str[i+1] == 't') res++;
            else break;
        }
        return res;
    }
    
    bool isFile(const std::string& str)
    {
        return str.find('.') != std::string::npos;
    }

public:
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        
        int len = 0;
        int start = 0;
        input.append("\\n");
        
        std::vector<int> tabLenMap(100, 0);
        int pos = input.find("\\n");
        int maxLen = 0;
        while( pos != std::string::npos) {
            auto curStr = input.substr(start, pos - start);
            start = pos + 2;
            int tabCount = countTab(curStr);
            int len = curStr.size()  - tabCount*2;
            tabLenMap[tabCount + 1] = tabLenMap[tabCount] + len + 1;
            if(isFile(curStr)) {
                maxLen = std::max(maxLen, tabLenMap[tabCount + 1] - 1);
            }
            pos = input.find("\\n", start);
        }
        
        return maxLen;
    }
};