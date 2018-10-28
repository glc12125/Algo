class Solution {
private:
    int m_magicNum = 33;
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        long long hash = 0;
        int len = key.size();
        for(int i = 0; i < len; ++i) {
            hash = (hash * m_magicNum + (int)key[i]) % HASH_SIZE;
        }
        return hash;
    }
};