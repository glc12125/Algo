class Solution {
private:
    struct UnionFind{
        std::vector<int> m_fathers;

        UnionFind(int n) {
            m_fathers.resize(n);
            for(int i = 0; i < n; ++i) {
                m_fathers[i] = i;
            }
        }

        int unionFind(int son) {
            if(m_fathers[son] == son) return son;
            m_fathers[son] = unionFind(m_fathers[son]);
            return m_fathers[son];
        }

        void unionMerge(int son1, int son2) {
            auto father1 = unionFind(son1);
            auto father2 = unionFind(son2);
            if(father1 != father2) {
                m_fathers[father1] = father2;
            }
        }
    };

public:
    /**
     * @param sets: Initial set list
     * @return: The final number of sets
     */
    int setUnion(vector<vector<int>> &sets) {
        int setNum = sets.size();
        if(setNum == 0) return 0;

        UnionFind uf(setNum);
        std::unordered_map<int, int> fatherMappings;
        for(int i = 0; i < setNum; ++i) {
            int lineNum = sets[i].size();
            for(int j = 0; j < lineNum; ++j) {
                if(fatherMappings.count(sets[i][j]) > 0) {
                    int father = fatherMappings[sets[i][j]];
                    uf.unionMerge(i, father);
                } else {
                    fatherMappings[sets[i][j]] = i;
                }
            }
        }

        std::unordered_set<int> merged;
        for(auto i : fatherMappings) merged.insert(uf.unionFind(i.second));
        return merged.size();
    }
};

// Union Find update number of set automatically
class Solution {
private:
    struct UnionFind{
        std::vector<int> m_fathers;
        int m_totalSet;

        UnionFind(int n) : m_totalSet(n) {
            m_fathers.resize(n);
            for(int i = 0; i < n; ++i) {
                m_fathers[i] = i;
            }
        }

        int unionFind(int son) {
            if(m_fathers[son] == son) return son;
            m_fathers[son] = unionFind(m_fathers[son]);
            return m_fathers[son];
        }

        void unionMerge(int son1, int son2) {
            auto father1 = unionFind(son1);
            auto father2 = unionFind(son2);
            if(father1 != father2) {
                m_fathers[father1] = father2;
                --m_totalSet;
            }
        }

        int totalSet() {return m_totalSet;}
    };

public:
    /**
     * @param sets: Initial set list
     * @return: The final number of sets
     */
    int setUnion(vector<vector<int>> &sets) {
        int setNum = sets.size();
        if(setNum == 0) return 0;

        UnionFind uf(setNum);
        std::unordered_map<int, int> fatherMappings;
        for(int i = 0; i < setNum; ++i) {
            int lineNum = sets[i].size();
            for(int j = 0; j < lineNum; ++j) {
                if(fatherMappings.count(sets[i][j]) > 0) {
                    int father = fatherMappings[sets[i][j]];
                    uf.unionMerge(i, father);
                } else {
                    fatherMappings[sets[i][j]] = i;
                }
            }
        }

        return uf.m_totalSet;
    }
};