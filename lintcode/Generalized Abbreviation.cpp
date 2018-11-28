class Solution {
private:
    void dfs(const string& word, int index, string abbrWord, bool abbred, vector<string>& result){
        int len = word.size();
        if(index == len){
            result.emplace_back(abbrWord);
            return;
        }

        dfs(word, index+1, abbrWord + word.at(index), false, result);

        if(!abbred){
            for(int j = index+1; j <= len; ++j){
                dfs(word, j, abbrWord + to_string(j-index), true, result);
            }
        }
    }
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        vector<string> result;
        dfs(word, 0, "", false, result);
        return result;
    }
};


//
class Solution {
private:
    void helper(const string& word, int pos, vector<string> &res) {
        int len = word.size();
        for (int i = pos; i < len; ++i) {
            for (int j = 1; i + j <= len; ++j) {
                string t = word.substr(0, i);
                t += to_string(j) + word.substr(i + j);
                res.push_back(t);
                helper(t, i + 1 + to_string(j).size(), res);
            }
        }
    }

public:
    vector<string> generateAbbreviations(string &word) {
        // Write your code here
        vector<string> res{word};
        helper(word, 0, res);
        return res;
    }
};


class Solution {
private:
    struct Digit {
        int m_number;
        int m_count;
        Digit() : m_number(0), m_count(0) {}
        Digit(int number, int count) : m_number(number), m_count(count) {}
    };

    bool isWordDigit(const string& word) {
        for(auto c : word) {
            if(!isdigit(c)) return false;
        }
        return true;
    }

    Digit getDigit(const string& word, int index, bool forward) {
        int digit = 0;
        int multiplier = 1;
        int count = 0;
        if(forward) {
            for(int i = index; i < word.size(); ++i) {
                if(isdigit(word[i])) {
                    digit = digit * multiplier + word[i] - '0';
                    multiplier *= 10;
                    ++count;
                } else {break;}
            }
        } else {
            for(int i = index; i >= 0; --i) {
                if(isdigit(word[i])) {
                    digit = digit + (word[i] - '0') * multiplier;
                    multiplier *= 10;
                    ++count;
                } else {break;}
            }
        }
        return Digit(digit, count);
    }

    void dfs(string word, unordered_set<string>& visited) {
        if(visited.count(word)) return;
        std::cout << "word: " << word << "\n";
        visited.insert(word);
        int len = word.size();
        if(isWordDigit(word)) return;

        for(int i = 0; i < len; ++i) {
            if(!isdigit(word[i])) {
                Digit forward;
                Digit backward;
                int newDigit = 1;
                if(i > 0 && isdigit(word[i-1])) {
                    backward = getDigit(word, i-1, false);
                }
                if(i < len - 1 && isdigit(word[i+1])) {
                    forward = getDigit(word, i+1, true);
                }
                newDigit += forward.m_number;
                newDigit += backward.m_number;
                string forwardPart = word.substr(i + forward.m_count + 1);
                string backwardPart = word.substr(0, i - backward.m_count);
                dfs(backwardPart + to_string(newDigit) + forwardPart, visited);
            }
        }
    }
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        unordered_set<string> visited;
        dfs(word, visited);
        return vector<string>(visited.begin(), visited.end());
    }
};