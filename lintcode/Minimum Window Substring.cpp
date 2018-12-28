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


/*
   0 1 2 3 4 5 6 7 8 9 10 11 12
S: A D O B E C O D E B A  N  C
T: ABC
mp: {A: 1, B: 1, C: 1}
count = 3
    i : 0,
        j : 0 - 5 -> count : 0
        j: 6
        res: ADOBEC
mp: {A: 0, B: 0, C: 0, D: -1, O: -1, E: -1}
count: 0
    move to next starting point 1, we should restore the counter if necessary. If the char is in t, then it should be zero by now
mp: {A: 1, B: 0, C: 0, D: -1, O: -1, E: -1}
count: 1
    i: 1,
        j: 6 - 10
        j: 11
        res: min(DOBECODEBA, ADOBEC) = ADOBEC
mp: {A: 0, B: -1, C: 0, D: -2, O: -2, E: -2}
count: 0
    move to next starting point 2
mp: {A: 0, B: -1, C: 0, D: -1, O: -2, E: -2}
count: 0
    i: 2, j: 11
    res: min(OBECODEBA, ADOBEC) = ADOBEC
count: 0
    move to next starting point 3
mp: {A: 0, B: -1, C: 0, D: -1, O: -1, E: -2}
count: 0
    i: 3, j: 11
    res: min(BECODEBA, ADOBEC) = ADOBEC
count: 0
    move to next starting point 4
mp: {A: 0, B: 0, C: 0, D: -1, O: -1, E: -2}
count: 0
    i: 4, j: 11
    res: min(ECODEBA, ADOBEC) = ADOBEC
count: 0
    move to next starting point 5
mp: {A: 0, B: 0, C: 0, D: -1, O: -1, E: -1}
count: 0
    i: 5, j: 11
    res: min(CODEBA, ADOBEC) = ADOBEC
count: 1
    move to next starting point 6
mp: {A: 0, B: -1, C: 1, D: -1, O: -1, E: 0}
count: 1
    i: 6,
        j: 11 - 12
        j: 13
    res: min(ODEBANC, ADOBEC) = ADOBEC
count: 0
    move to next starting point 7
mp: {A: 0, B: -1, C: 1, D: -1, O: 0, E: 0, N: -1}
count: 0
    i: 7, j: 13
    res: min(DEBANC, ADOBEC) = ADOBEC
count: 0
    move to next starting point 8
mp: {A: 0, B: -1, C: 1, D: -1, O: 1, E: 0, N: -1}
count: 0
    i: 8, j: 13
    res: min(EBANC, ADOBEC) = EBANC
count: 0
    move to next starting point 9
mp: {A: 0, B: 0, C: 1, D: -1, O: 1, E: 0, N: -1}
count: 0
    i: 9, j: 13
    res: min(BANC, ADOBEC) = BANC
count: 0
    move to next starting point 10
mp: {A: 0, B: 1, C: 1, D: -1, O: 1, E: 0, N: -1}
count: 1
....
NOTE: count will never become 0, thus it will never trigger res update

*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char now : t) {
            mp[now]++;
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