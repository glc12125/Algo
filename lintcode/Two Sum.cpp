// O(n) sspace and O(nlogn) time
class Solution {
private:
    struct Num{
        int m_val;
        int m_index;
        Num() = default;
        Num(int val, int index) : m_val(val), m_index(index) {}
    };
    
    struct LessValCompare{
        inline bool operator()(const Num& n1, const Num& n2) {
            return n1.m_val < n2.m_val;
        }
    };
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        if(len <= 1) return {};
        std::vector<Num> temp(len);
        for(int i = 0; i < len; ++i) {
            temp[i] = Num(numbers[i], i);
        }
        std::sort(temp.begin(), temp.end(), LessValCompare());
        int left = 0;
        int right = len - 1;
        int sum;
        while(left + 1 < right) {
            sum = temp[left].m_val + temp[right].m_val;
            if(sum < target) ++left;
            else if (sum > target) --right;
            else {
                std::vector<int> result = {temp[left].m_index, temp[right].m_index};
                std::sort(result.begin(), result.end());
                return result;
            }
        }
        if (temp[left].m_val + temp[right].m_val == target) {
            std::vector<int> result = {temp[left].m_index, temp[right].m_index};
            std::sort(result.begin(), result.end());
            return result;
        }
        return {};
    }
};

// With O(n) space and O(n) time
class Solution {
private:
    std::unordered_map<int, std::vector<int> > m_indexCache;
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        if(len <= 1) return {};
        
        for(int i = 0; i < len; ++i) {
            m_indexCache[numbers[i]].push_back(i);
        }
        
        for(int i = 0; i < len; ++i) {
            if(m_indexCache.count(target - numbers[i]) > 0) {
                int otherIndex;
                auto& indexes = m_indexCache[target - numbers[i]];
                return {i, indexes[indexes.size() - 1]};
            }
        }
        return {};
    }
};