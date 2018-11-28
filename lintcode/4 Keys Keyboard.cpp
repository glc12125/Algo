// Time O(N^2), space O(N)
class Solution {
public:
    /**
     * @param N: an integer
     * @return: return an integer
     */
    int maxA(int N) {
        /*
        There are two situations to complete N steps:
        1. Do Key 1 after N - 1 steps;
        2. Do Key 2/3/4 combinations
            - To finish a combination, there are at least 3 steps: select -> copy -> paste,
            - thus, we can perform a combination at most from (N - 3)th step;
            - Since key 4 can be performed multiple times, the starting point to perform combination is N = 1.
        */
        if (N <= 0) {
            return 0;
        }

        vector<int> counts(N + 1);
        for (int i = 1; i <= N; i++) {
            counts[i] = std::max(counts[i - 1] + 1, i);
            for (int j = 1; j <= i - 3; j++) {
                // After j steps, we have i - j steps left, and we also need 2 steps for key 2 and key 3.
                // Thus, we can perform at most i - j - 2 key 4 operations after j steps.
                // It gives us a total count as counts[j] + counts[j] * (i - j - 2) = counts[j] * (i - j - 1)
                counts[i]  = std::max(counts[i], counts[j] * (i - j - 1));
            }
        }

        return counts[N];
    }
};