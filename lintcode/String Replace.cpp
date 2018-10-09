class Solution {
private:
    int m_BASE = 1e6;
    int m_magic = 31;

public:
    /**
     * @param a: The A array
     * @param b: The B array
     * @param s: The S string
     * @return: The answer
     */
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        int size = a.size();
        if(a[size-1].size() > s.size()) return s;
        int sSize = s.size();
        int maxLen = 0;
        int hash;
        std::vector<int> aHash(size);
        std::vector<int> sHash;
        std::vector<int> powers;
        
        // Populate for a vector
        for(int i = 0; i < size; ++i) {
            hash = 1;
            const auto& item = a[i];
            for(int j = 0; j < item.size(); ++j) {
                hash = ((long long)hash * m_magic + item[j]) % m_BASE;
            }
            maxLen = std::max(maxLen, (int)item.size());
            aHash[i] = hash;
        }
        
        // Populate for s string
        hash = 0;
        sHash.push_back(hash);
        maxLen = max(maxLen, (int)sSize);
        for(int i = 0; i < sSize; i++) {
            hash = ((long long)hash * m_magic + s[i]) % m_BASE;
            sHash.push_back(hash);
        }
        hash = 1;
        powers.push_back(hash);
        for(int i = 0; i < maxLen; i++) {
            hash = (long long)hash * m_magic % m_BASE;
            powers.push_back(hash);
        }
        
        
        int indexB = 0;
        for(int i = 0; i < sSize; ++i) {
            int maxLen = -1;
            int indexB = -1;
            int aSsize;
            for(int ai = 0; ai < size; ++ai) {
                auto& aS = a[ai];
                aSsize = aS.size();
                int l = i;
                int r = i + aSsize;

                if(r > sSize) continue;
                int sHashValue = (sHash[r] - (long long)powers[r - l] * sHash[l] % m_BASE + m_BASE) % m_BASE;
                int aHashValue = (aHash[ai] - powers[aSsize] + m_BASE) % m_BASE;
                
                if(aHashValue == sHashValue && aSsize > maxLen) {
                    if(s.substr(i, aSsize) == aS) {
                        maxLen = aSsize;
                        indexB = ai;
                    }
                }
                
            }
            if(maxLen != -1) {
                s.replace(i, maxLen, b[indexB], 0, maxLen);
                i += maxLen - 1;
            }
        }
        
        return s;
    }
};