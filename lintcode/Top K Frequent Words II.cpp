class TopK {
private:

    int m_capacity;
    unordered_map<string, int> m_wordToCount;
    map<int, set<string>, std::greater<int>> m_countToWord;

    void enQueue(const string& word) {
        if(m_wordToCount.count(word)) {
            int currentCount = m_wordToCount[word]++;
            m_countToWord[currentCount].erase(word);
            m_countToWord[currentCount + 1].insert(word);
        } else {
            m_wordToCount[word]++;
            m_countToWord[1].insert(word);
        }
    }
public:
    /*
    * @param k: An integer
    */TopK(int k) : m_capacity(k) {

    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        enQueue(word);
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        int count = m_capacity;
        vector<string> result;
        for(auto& it : m_countToWord) {
            if(count <= 0) { break; }
            const auto& words = it.second;
            for(const auto& word : words) {
                result.emplace_back(word);
                if(--count == 0) { break; }
            }
        }
        return result;
    }
};