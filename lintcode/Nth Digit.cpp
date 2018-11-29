/*
As the author mentioned, integers can be divided into groups 1-9, 10-99, 100-999, 1000-9999, etc.
Every number in the i-th group has i digits. First we want to find the group which contains the number
where does the digit come from. (For example 2, the output comes from 10, which is in group 2.)

The first elements of these groups are 1, 10, 100, 1000...has the form 10**(digits-1) for digits in range(1, 11)
(11 is big enough to cover all n in the given range). But how do we determine the group from n? Notice
the groups has 9, 90, 900, 9000...elements and the total number of digits in the groups are 1＊9, 2＊90, 3＊900,
4＊9000.....Let's formalize the observation. For the digits-th group,

first = the first element
9 * first = the size of the group
9 * first * digits = the number of digits in the group
Therefore, in for loop, we first test if n <= 9 (the size of the first group). If not, n= n-9 due to {1,...,9}.
Then test if the new n <=2*90 (i.e. digits from 10-99). I'm lying a bit, since in the beginning n-=1
so all <= sign became < sign. When "n < 9 * first * digits" becomes true,

n means our return value is the n-th digits in the group of "digits" digits. Here the order starts from 0.
n/digits = the digits comes from the "n/digits" smallest number in the group.
Since the group starts with "first", first + n/digits= the number where the return value is one of the digits.
The digit we want is the "n%digits" digits in the number, starting from the left and the order starts from 0.
So the answer is str(first + n/digits)[n%digits], converted to int.
*/
class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the nth digit of the infinite integer sequence
     */
    int findNthDigit(int n) {
        int width = 1;
        long base = 9;
        while(n - width * base > 0) {
            n -= base * width;
            base *= 10;
            ++width;
        }

        int index = n%width;
        if(index==0) index = width;

        long num = 1;
        for(int i = 1; i < width; ++i) num *=10;

        num += (index == width)? n/width - 1:n/width;

        for(int i = index; i < width; ++i) {
            num /= 10;
        }

        return num % 10;

    }
};