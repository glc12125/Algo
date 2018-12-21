class HashFunction {
private:
    int m_cap;
    int m_seed;
public:
    HashFunction(int cap, int seed) : m_cap(cap), m_seed(seed) {
    }

    int hash(string& value) {
        int ret = 0;
        int n = value.size();
        for (int i = 0; i < n; ++i) {
            ret += m_seed * ret + value[i];
            ret %= m_cap;
        }
        return ret;
    }
};

static const int BLOOM_SIZE = 200000;

class CountingBloomFilter {
private:
    int m_k;
    vector<HashFunction> m_hashFunctions;
    vector<int> m_counters;
public:
    /*
    * @param k: An integer
    */CountingBloomFilter(int k) : m_k(k) {
        m_counters.resize(BLOOM_SIZE, 0);
        for(int i = 0; i < m_k; ++i) {
            m_hashFunctions.emplace_back(HashFunction(BLOOM_SIZE + i, 2 * i + 3));
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        for (int i = 0; i < m_k; ++i) {
            int position = m_hashFunctions[i].hash(word);
            ++m_counters[position];
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void remove(string &word) {
        for (int i = 0; i < m_k; ++i) {
            int position = m_hashFunctions[i].hash(word);
            --m_counters[position];
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        for(int i = 0; i < m_k; ++i) {
            int pos = m_hashFunctions[i].hash(word);
            if(m_counters[pos] == 0) {return false;}
        }
        return true;
    }
};