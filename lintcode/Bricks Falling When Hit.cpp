class Solution {
private:
    struct UnionFind {
        std::unordered_map<int, int> m_fathers;
        int m_topFather;
        int m_colSize;
        int m_totalDropNum;

        UnionFind(const std::vector<std::vector<int> > & grid) {
            int rowSize = grid.size();
            m_colSize = grid[0].size();
            m_topFather = rowSize*m_colSize;
            m_totalDropNum = 0;
            for(int i = 0; i < rowSize; ++i) {
                for(int j = 0; j < m_colSize; ++j) {
                    if(grid[i][j] == 1) {
                        int value = i*m_colSize+j;
                        if(i == 0) {
                            m_fathers[value] = m_topFather;
                        } else {
                            m_fathers[value] = -1;
                            ++m_totalDropNum;
                        }
                    }
                }
            }
        }
        
        int unionFind(int son) {
            if(m_fathers[son] < 0 || m_fathers[son] == m_topFather) return son;
            m_fathers[son] = unionFind(m_fathers[son]);
            return m_fathers[son];
            
        }
        
        void unionMerge(int son1, int son2) {
            auto father1 = unionFind(son1);
            auto father2 = unionFind(son2);
            if(father1 != father2) {
                if(m_fathers[father1] != m_topFather && m_fathers[father2] != m_topFather) {
                    m_fathers[father1] += m_fathers[father2];
                    m_fathers[father2] = father1;
                } else {
                    if(m_fathers[father1] < 0) m_totalDropNum += m_fathers[father1];
                    if(m_fathers[father2] < 0) m_totalDropNum += m_fathers[father2];
                    m_fathers[father1] = m_topFather;
                    m_fathers[father2] = m_topFather;
                }
            }
        }
        
        int dropNum(){
            return m_totalDropNum;
        }
    };
    
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
    int m_rowSize;
    int m_colSize;
    bool isValid(int i, int j) {
        return (-1 < i && i < m_rowSize && -1 < j && j < m_colSize);
    }
public:
    /**
     * @param grid: a grid
     * @param hits: some erasures order
     * @return: an array representing the number of bricks that will drop after each erasure in sequence
     */
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        m_rowSize = grid.size();
        if(m_rowSize == 0) return {};
        m_colSize = grid[0].size();
        if(m_colSize == 0) return {};
        
        int hitsNum = hits.size();
        for(int i = 0; i < hitsNum; ++i) {
            const auto& hit = hits[i];
            if(grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = -1;
        }

        UnionFind uf(grid);
        for(int i = 0; i < m_rowSize; ++i) {
            for(int j = 0; j < m_colSize; ++j) {
                if(grid[i][j] == 1) {
                    int son = i * m_colSize + j;
                    for(int k = 0; k < 4; ++k) {
                        int nextI = i + m_xMoves[k];
                        int nextJ = j + m_yMoves[k];
                        int nextSon = nextI * m_colSize + nextJ;
                        if(!isValid(nextI, nextJ)) continue;
                        if(grid[nextI][nextJ] == 1) {
                            uf.unionMerge(son, nextSon);
                        }
                    }
                }
            }
        }

        std::vector<int> result(hitsNum, 0);
        for(int i = hitsNum - 1; i > -1; --i) {
            const auto& hit = hits[i];

            if(grid[hit[0]][hit[1]] == 0) {
                result[i] = 0;
            } else if (grid[hit[0]][hit[1]] == -1){
                int beforeMerge = uf.dropNum();
                int x = hit[0];
                int y = hit[1];
                int son = x * m_colSize + y;
                if(uf.m_fathers.count(son) == 0) {
                    if(son < m_colSize) {
                        uf.m_fathers[son] = m_colSize * m_rowSize;
                    } else {
                        uf.m_fathers[son] = -1;
                        ++uf.m_totalDropNum;
                    }
                }
                for(int k = 0; k < 4; ++k) {
                    int nextI = x + m_xMoves[k];
                    int nextJ = y + m_yMoves[k];
                    int nextSon = nextI * m_colSize + nextJ;
                    if(!isValid(nextI, nextJ)) continue;
                    if(grid[nextI][nextJ] == 1) {
                        uf.unionMerge(son, nextSon);
                    }
                }
                grid[hit[0]][hit[1]] = 1;
                int afterMerge = uf.dropNum();
                result[i] = std::max(0, beforeMerge - afterMerge);
            }
        }
        return result;
    }
};