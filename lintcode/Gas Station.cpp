/*
1. 从i开始，j是当前station的指针，sum += gas[j] – cost[j] （从j站加了油，再算上从i开始走到j剩的油，走到j+1站还能剩下多少油）
2. 如果sum < 0，说明从i开始是不行的。那能不能从i..j中间的某个位置开始呢？既然i出发到i+1是可行的， 又i~j是不可行的， 从而发现i+1~ j是不可行的。
3. 以此类推i+2~j， i+3~j，i+4~j 。。。。等等都是不可行的
4. 所以一旦sum<0，index就赋成j + 1，sum归零。
5. 最后total表示能不能走一圈。
以上做法，其实是贪心的思想：

也就是说brute force的解是 ： 一个一个来考虑， 每一个绕一圈， 但是 实际上 我们发现 i - j不可行 直接index就跳到j+1， 这样周而复始，很快就是绕一圈 就得到解了。

算法证明：
1. 我们要证明当total > 0的时候，我们一定存在一个点，从它开始，可以绕一圈。

证明以下设定：

我们假定对任意i, j (i: 0 ~ len-1, j: 0 ~ len-1)，我们寻找sum =  Σ (gas[k]-cost[k]) (k 从i到j) ，使sum 最大。我们从i出发，一定可以绕一圈。

  i x x x x j x x x x m x

（1）假定存在这个一个m点，从i点出发，到m点会total（i-m） < 0. 也就是说从i出发不可以走完全程。

   => 因为Total > 0 而 total（i-m）<0 ，则必然 total ((m+1) ~ (i-1)) > 0 ，那么我们可以得出total ((m+1) ~ j) > total(i-j)，与total(i-j)是最大sum相违背。

   => 根据反证法，上述推定不能成立。所以不会存在这样一个m点，使total（i-m） < 0。也就是说从i出发，我们可以跑完全程。



2. 从1中我们可以看到，只要找到这样一个i-j区间，我们就能使汽车从i点出发，能够跑完全程。按照我们目前使用的算法，只要找到任何一个负区间，我们就丢弃，向下一个区间寻找，这其实就是找最大sum的算法。（因为前面如果是负区间你可以不加他们）最后得到的index实际上就是i （j我们并没有计算，实际上再从0 的index往后寻找一些正的station加上即是j的边界）。

所以从index出发汽车一定可以跑完一圈。另外，这样的解应该不止一个，在i-j之间，从i到n（n在i-j之间）都是可能的解。

实际上只要使total(n~j) >= -total(j+1 ~ i-1)即可， 同样假设假定存在这个一个m点，从n点出发，到m点会total（n-m） < 0. 则因为total(n~j) >= -total(j+1 ~ i-1)，同样可以推出total ((m+1) ~ (i-1)) > 0，与以上证明类似，同样会推翻题设。

例如：total(n~j) = 10， total(j+1 ~ i-1) = -9，如果total（n-m）= -1 ，则total ((m+1) ~ (i-1)) = 2 > 0



3. 总结：从i到m只要满足total(n~j) >= -total(j+1 ~ i-1)的点，都是可能的可以出发的点
*/

class Solution {
public:
    /**
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int total = 0;
        int index = -1;

        for(int i = 0; i<gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0) {
                index = i;
                sum = 0;
            }
        }
        return total < 0 ? -1 : index + 1;
    }
};