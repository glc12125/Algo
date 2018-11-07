/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done();
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, int value);
        while(!input->done()) {
            const auto& document = input->value();
            std::istringstream iss(document.content);
            for(std::string s; iss >> s;)
                output(s, 1);
            input->next();
        }
    }
};


class TopKFrequentWordsReducer: public Reducer {
private:
    struct WordFreq{
        string m_word;
        long long m_frequency;
        WordFreq() = default;
        WordFreq(const string& word, long long freq) : m_word(word), m_frequency(freq) {}
    };

    struct WordFreqCompare {
        bool operator()(const WordFreq& w1, const WordFreq& w2) const {
            return w1.m_frequency > w2.m_frequency || w1.m_frequency == w2.m_frequency && w1.m_word < w2.m_word;
        }
    };
    int m_k;
    priority_queue<WordFreq, vector<WordFreq>, WordFreqCompare> m_q;
public:
    void setUp(int k) {
        // initialize your data structure here
        m_k = k;
    }

    void Reduce(string &key, Input<int>* input) {
        long long freq = 0;
        while(!input->done()) {
            freq += input->value();
            input->next();
        }
        m_q.push(WordFreq(key, freq));
        if(m_q.size() > m_k) m_q.pop();
    }

    void cleanUp() {
        // Please directly use func 'output' to output
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);
        vector<WordFreq> result;
        while(!m_q.empty()) {
            auto wordFreq = m_q.top();
            result.push_back(wordFreq);
            m_q.pop();
        }
        for(int i = result.size() - 1; i > -1; --i) {
            output(result[i].m_word, result[i].m_frequency);
        }
    }
};