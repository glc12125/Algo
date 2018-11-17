class Solution {
private:
    void splitBy(const string& str, vector<string>& container, const string& delim) {
        /*stringstream ss(s);
        string token;
        while(getline(ss, token, delim)) {
            container.push_back(token);
        }*/
        std::size_t current, previous = 0;
        current = str.find(delim);
        while (current != std::string::npos) {
            container.push_back(str.substr(previous, current - previous));
            previous = current + 2;
            current = str.find(delim, previous);
        }
        container.push_back(str.substr(previous, current - previous));
    }

    int findLastOf(const string& str, const string& target) {
        int prev = -1;
        int curr = str.find(target);
        while(curr >= 0) {
            prev = curr;
            curr = str.find(target, prev + target.size());
        }
        return prev;
    }
public:
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        int len = input.size();
        if(len == 0) return 0;

        vector<string> lines;
        splitBy(input, lines, "\\n"); // Note that '\' is not used as escaping char

        vector<int> levelLength(len + 1, 0);
        int maxLen = 0;
        for(const auto& line : lines) {
            auto lastIndex = findLastOf(line, "\\t");
            int offSet = lastIndex == -1 ? 0 : lastIndex + 2;
            int level = lastIndex == -1 ? 1 : lastIndex / 2 + 2;
            int len = line.size() - offSet;
            if(line.find('.') != string::npos) {
                maxLen = std::max(maxLen, levelLength[level-1] + len);
            } else {
                levelLength[level] = levelLength[level-1] + len + 1;
            }
        }

        return maxLen;
    }
};

// Do not use extra O(N)(N is the number of \n) space to store parts of path
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