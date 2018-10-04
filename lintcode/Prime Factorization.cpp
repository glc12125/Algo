class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        std::vector<int> factors;
        for(int i = 2; i * i <= num; ++i) {
            while (num % i == 0) {
                factors.push_back(i);
                num /= i;
            }
        }

        if(num != 1) factors.push_back(num);
        return factors;
    }
};
