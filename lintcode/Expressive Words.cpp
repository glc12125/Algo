class Solution {
public:
    /**
     * @param S: a string
     * @param words: a list of strings
     * @return: return a integer
     */
    int expressiveWords(string &S, vector<string> &words) {
        int len = words.size();
        if(len == 0) return 0;
        int lenS = S.size();

        int count = 0;
        unordered_map<string, bool> cache;
        for(const auto& word : words) {
            int lenWord = word.size();
            if(lenWord > lenS) continue;
            if(cache.count(word)) {
                if(cache[word]) {++count;}
                else {continue;}
            }
            int i = 0;
            int j = 0;
            while(i < lenWord) {
                if(j < lenS - 2 && S[j] == S[j+1] && S[j] == S[j+2]) {
                    if(word[i] == S[j]) {
                        char repeatChar = S[j];
                        while(word[i] == repeatChar) {++i;}
                        while(repeatChar == S[j]) {++j;}
                    } else {
                        cache[word] = false;
                        break;
                    }
                } else {
                    if(word[i] == S[j]) {
                        ++i;
                        ++j;
                    } else {
                        cache[word] = false;
                        break;
                    }
                }
            }
            if(j == lenS && i == lenWord) {
                cache[word] = true;
                ++count;
            }
        }
        return count;
    }
};