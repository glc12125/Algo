class Solution {
private:
    struct PairCompare{
        bool operator()(const vector<int>& p1, const vector<int>& p2) const {
            if(p1[0] != p2[0]) {
                return p1[0] > p2[0];
            } else {
                return p1[1] < p2[1];
            }
        }
    };
public:
    /**
     * @param people: a random list of people
     * @return: the queue that be reconstructed
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), PairCompare());

        vector<vector<int>> result;
        for(const auto& p : people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }
};