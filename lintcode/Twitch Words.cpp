class Solution {
public:
    /**
     * @param str: the origin string
     * @return: the start and end of every twitch words
     */
    vector<vector<int>> twitchWords(string &str) {
        // Write your code here
        vector<vector<int>> result;

        int size = str.size();
        if(size < 3) return result;
        int end = 0;
        int counter[26] = {0};
        char candidate = ' ';
        char c = ' ';
        char prev = str[0];
        ++counter[prev - 'a'];
        for(int i = 1; i < size; ++i) {
            c = str[i];
            if(candidate != ' ' && c != candidate) {
                result.push_back({end - counter[candidate - 'a'] + 1, end});
                candidate = ' ';
                counter[candidate - 'a'] = 0;
            }
            if(counter[c-'a'] > 1) {
                candidate = c;
            }
            else if(counter[c-'a'] == 0){
                counter[prev-'a'] = 0;
            }
            ++end;
            ++counter[c-'a'];
            prev = c;
        }
        if(candidate != ' ' && c == candidate) {
            result.push_back({end - counter[candidate-'a'] + 1, end});
        }

        return result;
    }
};