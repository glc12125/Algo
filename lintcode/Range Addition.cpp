// Sweep line O(N + K)
class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // The values is a vector of size 2, first position records start range
        // and accumulated value, the second position records end range and
        // accumalted value as well
        unordered_map<int, vector<int>> operations;
        for(const auto& update : updates) {
            if(operations.count(update[0]) == 0) {
                operations[update[0]].resize(2);
                operations[update[0]][0] = 0;
            }
            if(operations.count(update[1]) == 0) {
                operations[update[1]].resize(2);
                operations[update[1]][1] = 0;
            }
            operations[update[0]][0] += update[2];
            operations[update[1]][1] += update[2];
        }

        int currentValue = 0;
        vector<int> result(length, 0);
        for(int i = 0; i < length; ++i) {
            if(operations.count(i) == 0) {
                result[i] = currentValue;
            } else {
                currentValue += operations[i][0];
                result[i] = currentValue;
                currentValue -= operations[i][1];
            }
        }
        return result;
    }
};

// Sweep line O(N + K)
class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        unordered_map<int, int> operations;
        for(const auto& update : updates) {
            operations[update[0]] += update[2];
            operations[update[1] + 1] -= update[2];
        }

        int currentValue = 0;
        vector<int> result(length, 0);
        for(int i = 0; i < length; ++i) {
            if(operations.count(i) == 0) {
                result[i] = currentValue;
            } else {
                currentValue += operations[i];
                result[i] = currentValue;
            }
        }
        return result;
    }
};