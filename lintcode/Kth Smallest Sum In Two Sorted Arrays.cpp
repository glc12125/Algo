class Solution {
private:
    struct Element{
        int m_aIndex;
        int m_bIndex;
        long m_sum;
        
        Element() = default;
        Element(int aIndex, int bIndex, long sum) : m_aIndex(aIndex), m_bIndex(bIndex), m_sum(sum) {}
    };
    
    struct ElementCompare {
        bool operator()(const Element& e1, const Element& e2) const {
            return e1.m_sum > e2.m_sum;
        }
    };
    
    int getKey(int lenB, int indexA, int indexB) {
        return indexA * lenB + indexB;
    }
    
    int m_aMoves[2] = {1, 0};
    int m_bMoves[2] = {0, 1};
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        int lenA = A.size();
        int lenB = B.size();
        if(lenA == 0 || lenB == 0 || k <= 0) return -1;
        if(k > lenA * lenB) return -1;
        
        std::priority_queue<Element, std::vector<Element>, ElementCompare> orderedContainer;
        std::unordered_set<int> visited;
        int aIndex = 0;
        int bIndex = 0;
        orderedContainer.push(Element(aIndex, bIndex, (long)A[aIndex] + B[bIndex]));
        visited.insert(getKey(lenB, aIndex, bIndex));
        for(int i = 0; i < k - 1; ++i) {
            auto curr = orderedContainer.top();
            orderedContainer.pop();

            for(int j = 0; j < 2; ++j) {
                int nextAindex = curr.m_aIndex + m_aMoves[j];
                int nextBindex = curr.m_bIndex + m_bMoves[j];
                int key = getKey(lenB, nextAindex, nextBindex);
                if(visited.count(key) || nextAindex >= lenA || nextBindex >= lenB) continue;
                Element next(nextAindex, nextBindex, (long)A[nextAindex] + B[nextBindex]);
                orderedContainer.push(next);
                visited.insert(key);
            }
        }
        
        return orderedContainer.top().m_sum;
    }
};