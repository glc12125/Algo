#include <bitset>


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

class StandardBloomFilter {
private:
    int m_k;
    vector<HashFunction> m_hashFunctions;
    bitset<20000> m_bits;
public:
    /*
    * @param k: An integer
    */StandardBloomFilter(int k) : m_k(k) {
        for(int i = 0; i < m_k; ++i) {
            m_hashFunctions.emplace_back(HashFunction(10000 + i, 2 * i + 3));
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        for (int i = 0; i < m_k; ++i) {
            int position = m_hashFunctions[i].hash(word);
            m_bits.set(position);
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        for(int i = 0; i < m_k; ++i) {
            int pos = m_hashFunctions[i].hash(word);
            if(!m_bits[pos]) {return false;}
        }
        return true;
    }
};