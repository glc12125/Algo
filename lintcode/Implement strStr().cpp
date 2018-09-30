class Solution {
private:
    int m_BASE = 1e6;
    int m_magic = 31;
public:
    /**
     * @param source:
     * @param target:
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        int sourceS = source.size();
        int targetS = target.size();
        if(targetS == 0) return 0;

        int power = 1;
        for(int i = 0; i < targetS; ++i) {
            power = (power * m_magic) % m_BASE;
        }
        int targetHash = 0;
        for(int i = 0; i < targetS; ++i) {
            targetHash = (targetHash * m_magic + target[i]) % m_BASE;
        }

        int sourceHash = 0;
        for(int i = 0; i < sourceS; ++i) {
            // targe + t
            sourceHash = (sourceHash * m_magic + source[i]) % m_BASE;

            if(i < targetS - 1) continue;
            // targeta - t
            if(i >= targetS) {
                sourceHash = sourceHash - (power*source[i-targetS]) % m_BASE;
                if(sourceHash < 0) sourceHash += m_BASE;
            }
            if(sourceHash == targetHash) {
                if(source.substr(i - targetS + 1, targetS) == target) return i - targetS + 1;
            }
        }

        return -1;
    }
};