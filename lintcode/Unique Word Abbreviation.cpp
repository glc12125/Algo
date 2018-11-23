class ValidWordAbbr {
private:
    string getAbbr(const string& s) {
        if(s.size() < 3) return "";

        return s[0] + to_string(s.size() - 2) + s.back();
    }

    unordered_map<string, unordered_set<string>> m_uniqueAbbr;
public:
    /*
    * @param dictionary: a list of words
    */ValidWordAbbr(vector<string> dictionary) {
        for(const auto& word : dictionary) {
            const auto& abbr = getAbbr(word);
            if(abbr.empty()) continue;
            m_uniqueAbbr[abbr].insert(word);
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        const auto& abbr = getAbbr(word);
        if(m_uniqueAbbr.count(abbr)) {
            if(m_uniqueAbbr[abbr].size() > 1) return false;
            else {
                if(m_uniqueAbbr[abbr].count(word) == 0) return false;
            }
        }
        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */