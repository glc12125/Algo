class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        int len = chars.size();
        if(len <= 1) return;

        int l = 0;
        int r = len - 1;
        while(l <= r) {
            while(l <= r && islower(chars[l])) { ++l; }
            while(l <= r && !islower(chars[r])) { --r; }
            if(l <= r) {
                swap(chars[l++], chars[r--]);
            }
        }
    }
};