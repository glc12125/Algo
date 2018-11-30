class Solution {
private:
    bool isPalindrome(int val) {
        int num = val;
        int rev = 0;
        int digit = 0;
        do
        {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);
        return val == rev;
    }

    bool isPalindrome2(const std::string& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
public:
    /**
     * @param L: A positive integer
     * @param R: A positive integer
     * @return:  the number of interesting subranges of [L,R]
     */
    int PalindromicRanges(int L, int R) {
        int rangeLen = R - L + 1;
        std::vector<int> flags(rangeLen, 0);
        for(int i = L; i < R + 1; ++i) {
            flags[i-L] = isPalindrome(std::to_string(i)) ? 1 : 0;
        }

        int totalNum = 0;
        for(int i = 0; i < rangeLen; ++i) {
            int count = 0;
            for(int j = i; j < rangeLen; ++j){
                count += flags[j];
                if (count % 2 == 0) ++totalNum;
            }
        }

        return totalNum;
    }
};