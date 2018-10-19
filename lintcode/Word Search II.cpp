class Solution {
private:
    struct TrieNode {
        bool m_wordEnd;
        TrieNode* m_next[26] = { nullptr };
        TrieNode() : m_wordEnd(false) {}
    };
    class Trie{
    public:

        int m_xMoves[4] = {-1, 0, 1, 0};
        int m_yMoves[4] = {0, 1, 0, -1};
        int m_rowSize;
        int m_colSize;

        bool isValid(int i, int j) {
            return (-1 < i && i < m_rowSize && -1 < j && j < m_colSize);
        }

        TrieNode * m_head;
        std::vector<std::string> m_results;
        Trie(int rowSize, int colSize) : m_rowSize(rowSize), m_colSize(colSize) {
            m_head = new TrieNode();
        }

        ~Trie() {
            // TODO
        }

        void search(vector<vector<char> > &board, vector<vector<bool> > &mask, TrieNode* node, std::string word, int x, int y) {
            if (node->m_wordEnd) {
                m_results.push_back(word);
                node->m_wordEnd = false;
            }

            mask[x][y] = false;
            for(int i = 0; i < 4; ++i){
                int nextX = x + m_xMoves[i];
                int nextY = y + m_yMoves[i];
                if(!isValid(nextX, nextY)) continue;
                if(!mask[nextX][nextY]) continue;
                if(node->m_next[board[nextX][nextY]-'a'] == nullptr) continue;
                search(board, mask, node->m_next[board[nextX][nextY]-'a'], word + board[nextX][nextY], nextX, nextY);
            }
            mask[x][y] = true;
        }

        void insert(const std::string& word) {
            TrieNode * curr = m_head;
            for(int i = 0; i < word.size(); ++i) {
                if(curr->m_next[word[i] - 'a'] == nullptr) {
                    curr->m_next[word[i] - 'a'] = new TrieNode();
                }
                curr = curr->m_next[word[i] - 'a'];
            }
            curr->m_wordEnd = true;
        }
    };

public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        int rowSize = board.size();
        if(rowSize == 0) return {};
        int colSize = board[0].size();
        if(colSize == 0) return {};

        Trie t(rowSize, colSize);
        for(const auto& word : words) {
            t.insert(word);
        }

        std::vector<std::vector<bool> > mask(rowSize, vector<bool>(colSize, true));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
               if (t.m_head->m_next[board[i][j]-'a'] != NULL) {
                    t.search(board, mask, t.m_head->m_next[board[i][j]-'a'], std::string(1, board[i][j]), i, j);
                }
            }
        }
        return t.m_results;
    }
};