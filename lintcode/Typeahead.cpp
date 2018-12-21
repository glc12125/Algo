class Typeahead {
private:
    vector<string> m_dictWords;
    unordered_map<string, set<int>> m_uniqueMappings;
public:
    /*
    * @param dict: A dictionary of words dict
    */
    Typeahead(unordered_set<string> dict) {
        for(const auto& word : dict) {
            int len = word.size();
            for(int i = 0; i < len; ++i) {
                for(int j = i; j < len; ++j) {
                    string key = word.substr(i, j - i + 1);
                    m_uniqueMappings[key].insert(m_dictWords.size());
                }
            }
            m_dictWords.emplace_back(word);
        }
    }

    /*
     * @param str: a string
     * @return: a list of words
     */
    vector<string> search(string &str) {
        vector<string> result;
        if(m_uniqueMappings.count(str) == 0) {
            return result;
        }
        for(auto index : m_uniqueMappings[str]) {
            result.push_back(m_dictWords[index]);
        }
        return result;
    }
};