// time O(N)
/*
利用异或的特性, 这题可以有更好的解法. 对于异或运算, 我们有

如果a ^ b = c, 那么a ^ c = b.

根据这个定理, 我们从最高位开始找, 我们先将所有数的最高位存到一个Set中. 然后, 我们假设最终答案的最高位为1, 将数列中所有数的最高位和1进行异或运算, 异或得到的结果仍然在Set中, 那么说明最终答案的最高位一定为1, (由定理可得1 ^ x = b <==> b ^ x = 1, 对与数x, 一定存在一个数b, 使得x ^ b = 1), 否则最高位的答案一定为0.

假设我们已经知道最终答案的最高k位为prefix, 我们先将数列中所有数的最高k+1位存入Set中. 然后, 我们假设下一位的值为1, 将数列中所有数的最高k+1位与prefix*2 + 1进行异或运算, 如果异或得到的结果仍然在Set中, 那么说明最终答案的第k+1位一定为1, 否则, 最高位的答案一定为0.

因为x ^ (prefix2+1) = b　<==> x ^ b = prefix2+1, 即对于数x, 一定存在一个数b, 使得他们异或的结果为prefix*2+1.

因此, 我们可以对最终答案的32位进行依次判断, 最终得到异或的最大值.

该算法的时间复杂度为O(32n) = O(n).
*/
class Solution {
public:
    /**
     * @param nums:
     * @return: the maximum result of ai XOR aj, where 0 â‰¤ i, j < n
     */
    int findMaximumXOR(vector<int> &nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};