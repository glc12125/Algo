class Solution {
private:
    struct Node {
        char m_c;
        int m_index;
        Node() = default;
        Node(char c, int index) : m_c(c), m_index(index) {}
    };
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        unordered_map<char, int> charCounters;

        int totalMatch = 0;
        int minIndex;
        int maxIndex;
        for(auto c : target) {
            ++charCounters[c];
            ++totalMatch;
        }

        unordered_map<char, int> counterBuffer;
        vector<Node> indexes;
        int start = 0;
        int end = 0;
        int minLength = INT_MAX;
        string result;
        for(int i = 0; i < source.size(); ++i) {
            if(charCounters.count(source[i]) == 0) continue;
            if(counterBuffer[source[i]] < charCounters[source[i]]) --totalMatch;

            indexes.push_back(Node(source[i], i));
            ++counterBuffer[source[i]];

            if(totalMatch == 0) { // all found
                while(counterBuffer[indexes[start].m_c] > charCounters[indexes[start].m_c]) {
                    --counterBuffer[indexes[start].m_c];
                    ++start;
                }
                end = indexes.size() - 1;
                // also calculate min length
                if( minLength > indexes[end].m_index - indexes[start].m_index + 1) {
                    result = source.substr(indexes[start].m_index, indexes[end].m_index - indexes[start].m_index + 1);
                    minLength = end - start + 1;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char now : t) {
            mp[now] ++;
        }
        int count = mp.size();
        int j = 0;
        int ans = INT_MAX;
        string res;
        for (int i = 0; i < s.size(); i++) {
            while(count != 0 && j < s.size()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
                j++;
                if (count == 0) {
                    break;
                }
            }
            if (count == 0 && j - i< ans) {
                ans = j - i;
                res = s.substr(i, j - i);

            }
            if(mp[s[i]] == 0) {
                count++;
            }
            mp[s[i]]++;
        }
        return res;
    }
};