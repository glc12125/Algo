class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int carry = 1;
        int sum = 0;
        for(int i = size - 1; i > -1; --i) {
            sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);

        return digits;
    }
};