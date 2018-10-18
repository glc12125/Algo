// Union Find, Time O(n*m*logm), space O(n*m)
class Solution {
private:
    int unionFind(std::vector<int>& fathers, int son) {
        if(fathers[son] == son) return son;
        fathers[son] = unionFind(fathers, fathers[son]);
        return fathers[son];
    }

    void unionMerge(std::vector<int>& fathers, int son1, int son2){
        auto father1 = unionFind(fathers, son1);
        auto father2 = unionFind(fathers, son2);

        if(father1 != father2) {
            fathers[father1] = father2;
        }
    }
public:
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {

        int accountsNum = accounts.size();
        if(accountsNum == 0) return vector<vector<string>>();

        std::vector<int> fathers(accountsNum);
        for(int i = 0; i < accountsNum; ++i) fathers[i] = i;

        std::unordered_map<std::string, int> fatherMappings;

        for(int i = 0; i < accountsNum; ++i) {
            int accountSize = accounts[i].size();
            for(int j = 1; j < accountSize; ++j) {
                if(fatherMappings.count(accounts[i][j]) > 0) {
                    int father = fatherMappings[accounts[i][j]];
                    if(accounts[father][0] == accounts[i][0]) unionMerge(fathers, father, i);
                } else {
                    fatherMappings[accounts[i][j]] = i;
                }
            }
        }

        std::unordered_map<int, std::set<std::string> > merged;
        for(int i = 0; i < accountsNum; ++i) {
            int father = unionFind(fathers, i);
            merged[father].insert(accounts[i].begin(), accounts[i].end());
        }

        vector<vector<string>> result;
        for(auto answer: merged) {
            result.push_back(std::vector<std::string>(answer.second.begin(), answer.second.end()));
        }
        return result;
    }
};

