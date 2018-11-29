class Solution {
public:
    /**
     * @param nums: List[int]
     * @return: return List[str]
     */
    vector<string> findRelativeRanks(vector<int> &nums) {
        int size = nums.size();
        std::vector<std::string> result(size);
        std::map<int, int> ranks;
        for(int i = 0; i < size; ++i) {
            ranks[nums[i]] = i;
        }
        int relativeRank = size;
        for(auto it : ranks) {
            int pos = it.second;
            std::string name;
            if(relativeRank > 3) {
                result[pos] = std::to_string(relativeRank);
            } else {
                if(relativeRank == 3) {
                    name = "Bronze Medal";
                } else if (relativeRank == 2) {
                    name = "Silver Medal";
                } else {
                    name = "Gold Medal";
                }
                result[pos] = name;
            }
            --relativeRank;
        }
        return result;
    }
};