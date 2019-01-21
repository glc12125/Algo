class Solution {
public:
    /**
     * @param s: the given string s
     * @param t: the given string t
     * @return: check if s is subsequence of t
     */
    bool isSubsequence(string &s, string &t) {
        int len = s.size();
        if(len == 0) return true;
        int tLen = t.size();
        if(tLen == 0) return false;

        int sIndex = 0;
        int tIndex = 0;
        while(sIndex < len && tIndex < tLen) {
            while(tIndex < tLen && s[sIndex] != t[tIndex]) {
                ++tIndex;
            }
            if(s[sIndex] == t[tIndex]) {
                ++sIndex;
            }
        }

        return sIndex == len;
    }
};

// Binary search O(slogt)
class Solution {
private:
    int find(const vector<int>& indexes, int currentIndex) {
        int len = indexes.size();
        if(len == 0) return -1;
        int l = 0;
        int r = len - 1;
        if(currentIndex > indexes[r]) return -1;

        while(l + 1 < r) {
            int mid = (l + r) / 2;
            if(indexes[mid] <= currentIndex) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if(indexes[l] > currentIndex) {return indexes[l];}
        return indexes[r];
    }
public:
    /**
     * @param s: the given string s
     * @param t: the given string t
     * @return: check if s is subsequence of t
     */
    bool isSubsequence(string &s, string &t) {
        int len = s.size();
        if(len == 0) return true;
        int tLen = t.size();
        if(tLen == 0) return false;

        vector<vector<int>> charIndexes(26);

        for(int i = 0; i < tLen; ++i) {
            charIndexes[t[i] - 'a'].push_back(i);
        }

        int currentIndex = 0;
        for(auto c : s) {
            int nextIndex = find(charIndexes[c-'a'], currentIndex);
            if(nextIndex == -1) return false;
            currentIndex = nextIndex;
        }
        return true;
    }
};