class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        std::sort(str.begin(), str.end());
        int size = str.size();
        for(int i = 0; i < size; ++i) {
            if(str[i] != str[i+1] && i == 0) return str[i];
            if(str[i] != str[i+1] && str[i] != str[i-1] && i > 1 && str[i-1] == str[i-2] && i < size - 2 && str[i+1] == str[i+2]) return str[i];
            if(str[i] != str[i+1] && str[i] != str[i-1] && i > 1 && str[i-1] == str[i-2]) return str[i+1];
            if(i == size -1 && str[i] != str[i-1]) return str[i];
        }
    }
};