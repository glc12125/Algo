class Solution {
private:
    int find(std::vector<int>& fathers, int son) {
        if(fathers[son] == 0) return son;
        fathers[son] = find(fathers, fathers[son]);
        return fathers[son];
    }
public:
    /**
     * @param ListA: The relation between ListB's books
     * @param ListB: The relation between ListA's books
     * @return: The answer
     */
    vector<string> maximumAssociationSet(vector<string> &ListA, vector<string> &ListB) {
        if(ListA.size() != ListB.size()) return {};
        if(ListA.size() == 0) return {};
        int listSize = ListA.size();
        std::unordered_map<std::string, int> keys;
        int counter = 0;
        for(int i = 0; i < listSize; ++i) {
            if(keys.count(ListA[i]) == 0) keys[ListA[i]] = ++counter;
            if(keys.count(ListB[i]) == 0) keys[ListB[i]] = ++counter;
        }

        std::vector<int> fathers(counter+1, 0);
        for(int i = 0; i < listSize; ++i) {
            auto key1 = keys[ListA[i]];
            auto key2 = keys[ListB[i]];

            auto father1 = find(fathers, key1);
            auto father2 = find(fathers, key2);
            if(father1 != father2) {
                fathers[father1] = father2;
            }
        }

        std::unordered_map<int, std::unordered_set<std::string> > answers;
        for(int i = 0; i < listSize; ++i) {
            auto key1 = keys[ListA[i]];
            auto key2 = keys[ListB[i]];
            auto father1 = find(fathers, key1);
            auto father2 = find(fathers, key2);
            answers[father1].insert(ListA[i]);
            answers[father2].insert(ListB[i]);
        }

        size_t maxLen = 0;
        for(auto i : answers) {
            maxLen = std::max(maxLen, i.second.size());
        }

        for(auto i : answers) {
            if(maxLen == i.second.size()) return std::vector<std::string>(i.second.begin(), i.second.end());
        }
    }
};