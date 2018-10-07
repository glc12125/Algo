class Solution {
private:
struct Number
{
    int m_index;
    int m_val;
    Number(int index, int val) : m_index(index) , m_val(val) {}
};

struct less_than_value
{
    inline bool operator() (const Number& n1, const Number& n2)
    {
        return (n1.m_val < n2.m_val);
    }
};
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 2) return {};
        std::vector<Number> numbers;
        for(int i = 0; i < len; ++i) {
            numbers.push_back(Number(i+1, nums[i]));
        }
        std::sort(numbers.begin(), numbers.end(), less_than_value());
        for(auto number : numbers)
            std::cout << number.m_val << " ";
        std::cout << "\n";
        int end = 1;
        if(target < 0) target = -target;
        for(int start = 0; start < len; ++start){
            if(start == end) ++end;
            while(end < len && numbers[end].m_val - numbers[start].m_val < target) ++end;

            if(end < len && numbers[end].m_val - numbers[start].m_val == target){
                std::vector<int> result = {numbers[start].m_index, numbers[end].m_index};
                std::sort(result.begin(), result.end());
                return result;

            }
        }
        return {-1, -1};
    }
};

// Using Hash Table
class Solution {
private:
    std::unordered_map<int, int> m_cache;
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 2) return {};
        for(auto i : nums) ++m_cache[i];
        int values[2] = {0};
        for(int i = 0; i < len; ++i) {
            if(m_cache[target + nums[i]] > 0) {
                values[0] = nums[i];
                values[1] = target + nums[i];
            }
        }

        std::vector<int> result;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == values[0]) result.push_back(i+1);
            if(values[0] != values[1] && nums[i] == values[1]) result.push_back(i+1);
        }
        return result;
    }
};