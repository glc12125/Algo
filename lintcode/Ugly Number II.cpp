// Time O(nlogn), remember to avoid duplicates
class Solution {
private:
    int m_factors[3] = {2, 3, 5};
    std::priority_queue<long, std::vector<long>, std::greater<long> > m_q;
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        std::unordered_set<int> found;
        for(int i = 0; i < 3; ++i) {
            m_q.push(m_factors[i]);
            found.insert(m_factors[i]);
        }
        long result = 1;
        for(int i = 1; i < n; ++i) {
            result = m_q.top();
            m_q.pop();
            for(int j = 0; j < 3; ++j) {
                long next = result * m_factors[j];
                if(found.count(next)) continue;
                m_q.push(next);
                found.insert(next);
            }
        }
        return result;
    }
};