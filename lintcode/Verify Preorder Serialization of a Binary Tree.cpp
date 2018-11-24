//DFS
class Solution {
private:
    bool dfs(const string& s, int& index) {
        if(index == s.size()) return true;

        if(isdigit(s[index])) {
            while(isdigit(s[index])) ++index;
            return dfs(s, ++index) && dfs(s, ++index);
        } else {
            return s[index++] == '#';
        }
    }
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        int curr = 0;
        return dfs(preorder, curr) && curr == preorder.size();
    }
};

// Iterative
class Solution {
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        string s(preorder);
        bool flag = true;
        while (s.size() > 1) {
            std::cout << "s: " << s << "\n";
            int index = s.find(",#,#");
            if (index == string::npos) {
                flag = false;
                break;
            }
            int start = index;
            while (start > 0 && s.at(start - 1) != ',')
            {
                start--;
            }
            if (s.at(start) == '#') {
                flag = false;
                break;
            }
            s = s.substr(0, start) + s.substr(index + 3);
        }
        if (s == "#" && flag)
            return true;
        else
            return false;
    }
};