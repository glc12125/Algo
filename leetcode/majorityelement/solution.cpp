#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
    unordered_map<int, int> d_occur;
public:
    int majorityElement(vector<int> &nums)
    {
        vector<int>::iterator itr;
        size_t length = nums.size();
        if (length == 1) {
            return nums.front();
        }
        for (itr = nums.begin(); itr != nums.end(); ++itr) {
            unordered_map<int, int>::iterator item = d_occur.find(*itr);
            if (item != d_occur.end()) {
                if ( ++(item->second) > length / 2) {
                    return *itr;
                }
            } else {
                d_occur.insert(make_pair(*itr, 1));
            }
        }

        return 0;

    }

};
