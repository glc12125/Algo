// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        int num = 0;
        while (start <= end) {
            num = start + rand() % (( end + 1 ) - start);// extreme case like 2147483647 will make it linear
            int result = guess(num);
            if(result == 0) return num;
            else if (result == 1) start = num + 1;
            else if (result == -1) end = num - 1;
        }
    }
};