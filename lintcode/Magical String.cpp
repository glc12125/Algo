class Solution {
public:
    /**
     * @param n: an integer
     * @return: the number of '1's in the first N number in the magical string S
     */
    int magicalString(int n) {
        if(n == 0) return 0;
        if(n < 3) return 1;
        string magicString("122");
        for(int i = 2; magicString.size() < n; ++i) {
            magicString += string(magicString[i] - '0', magicString.back()^3);
        }
        return count(magicString.begin(), magicString.begin() + n, '1');
    }
};