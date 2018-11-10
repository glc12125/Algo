/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    void flattenDfs(const vector<NestedInteger> &nestedList, vector<int>& result) {
        for(const auto& item : nestedList) {
            if(item.isInteger()) result.push_back(item.getInteger());
            else {
                flattenDfs(item.getList(), result);
            }
        }
    }
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> result;

        flattenDfs(nestedList, result);
        return result;
    }
};

// iterative, takes much longer time depending on how nested the data is
class Solution {
private:
    void flattenDfs(const vector<NestedInteger> &nestedList, vector<int>& result) {
        for(const auto& item : nestedList) {
            if(item.isInteger()) result.push_back(item.getInteger());
            else {
                flattenDfs(item.getList(), result);
            }
        }
    }

public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {

        vector<NestedInteger> temp = nestedList;
        bool hasNested = true;
        while(hasNested) {
            hasNested = false;
            vector<NestedInteger> buffer;
            for(auto item : temp) {
                if(item.isInteger()) buffer.push_back(item);
                else {
                    buffer.insert(buffer.end(), item.getList().begin(), item.getList().end());
                    hasNested = true;
                }
            }
            temp = buffer;
        }
        vector<int> result;
        for(auto item : temp) {
            result.push_back(item.getInteger());
        }

        return result;

    }
};