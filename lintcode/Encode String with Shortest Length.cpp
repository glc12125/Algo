// Time O(N^3), space O(N^2)
/*
这道题让我们压缩字符串，把相同的字符串用中括号括起来，然后在前面加上出现的次数，
感觉还是一道相当有难度的题呢。参考了网上大神的帖子才弄懂该怎么做，这道题还是应该用DP来做。
我们建立一个二维的DP数组，其中dp[i][j]表示s在[i, j]范围内的字符串的缩写形式(如果缩写形式长度大于子字符串，
那么还是保留子字符串)，那么如果s字符串的长度是n，最终我们需要的结果就保存在dp[0][n-1]中，
然后我们需要遍历s的所有子字符串，对于任意一段子字符串[i, j]，我们\\我们以中间任意位置k来拆分成两段，
比较dp[i][k]加上dp[k+1][j]的总长度和dp[i][j]的长度，将长度较小的字符串赋给dp[i][j]，
然后我们要做的就是在s中取出[i, j]范围内的子字符串t进行合并。合并的方法是我们在取出的字符串t后面再加上一个t，
然后在这里面寻找子字符串t的第二个起始位置，如果第二个起始位置小于t的长度的话，说明t包含重复字符串，
举个例子吧，比如 t = "abab", 那么t+t = "abababab"，我们在里面找第二个t出现的位置为2，小于t的长度4，
说明t中有重复出现，重复的个数为t.size()/pos = 2个，那么我们就要把重复的地方放入中括号中，
注意中括号里不能直接放这个子字符串，而是应该从dp中取出对应位置的字符串，因为重复的部分有可能已经写成缩写形式了，
比如题目中的例子5。再看一个例子，如果t = "abc"，那么t+t = "abcabc"，我们在里面找第二个t出现的位置为3，
等于t的长度3，说明t中没有重复出现，那么replace就还是t。然后我们比较我们得到的replace和dp[i][j]中的字符串长度，
把长度较小的赋给dp[i][j]即可，时间复杂度为O(n3)，空间复杂度为O(n2)
*/
class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string encode(string &s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int step = 1; step <= n; ++step) {
            for (int i = 0; i + step - 1 < n; ++i) {
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);
                string t = s.substr(i, j - i + 1), replace = "";
                auto pos = (t + t).find(t, 1);
                if (pos < t.size()) {
                    replace = to_string(t.size() / pos) + "[" + dp[i][i + pos - 1] + "]";
                    if (replace.size() < dp[i][j].size()) dp[i][j] = replace;
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    string left = dp[i][k], right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};