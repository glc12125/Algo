// Time O(M+N)
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

// KMP, time O(M+N)
class Solution {
private:
    // Fills lps[] for given patttern pat[0..M-1]
    void computeLPSArray(const char* pat, int M, int* lps)
    {
        // length of the previous longest prefix suffix
        int len = 0;

        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else // (pat[i] != pat[len])
            {
                // This is tricky. Consider the example.
                // AAACAAAA and i = 7. The idea is similar
                // to search step.
                if (len != 0) {
                    len = lps[len - 1];

                    // Also, note that we do not increment
                    // i here
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Prints occurrences of txt[] in pat[]
    int KMPSearch(const char* pat, const char* txt)
    {
        int M = strlen(pat);
        int N = strlen(txt);

        // create lps[] that will hold the longest prefix suffix
        // values for pattern
        int lps[M];

        // Preprocess the pattern (calculate lps[] array)
        computeLPSArray(pat, M, lps);

        int firstIndex = -1;
        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while (i < N) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                if(firstIndex == -1) {
                    firstIndex = i - j;
                }
                j = lps[j - 1];
            }

            // mismatch after j matches
            else if (i < N && pat[j] != txt[i]) {
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return firstIndex;
    }
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
    int strStr2(const char* source, const char* target) {
        if(source == nullptr || target == nullptr) return -1;
        int sourceS = strlen(source);
        int targetS = strlen(target);
        if(targetS == 0) return 0;

        return KMPSearch(target, source);
    }
};