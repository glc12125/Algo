class Solution {
private:
    class Trie{
    private: 
        struct TrieNode {
            bool m_wordEnd;
            TrieNode* m_next[26] = { nullptr };
            TrieNode() : m_wordEnd(false) {}
        };
        
        TrieNode * m_head;
    public:
        Trie() {
            m_head = new TrieNode();
        }
        
        ~Trie() {
            // TODO
        }
        
        bool search(const std::string& word) {
            TrieNode * curr = m_head;
            for(int i = 0; i < word.size(); ++i) {
                if(curr->m_next[word[i] - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->m_nex[word[i] - 'a'];
            }
            return curr->m_wordEnd;
        }
        
        bool startWith(const std::string& word) {
            TrieNode * curr = m_head;
            for(int i = 0; i < word.size(); ++i) {
                if(curr->m_next[word[i] - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->m_nex[word[i] - 'a'];
            }
            return true;
        }
        
        void insert(const std::string& word) {
            TrieNode * curr = m_head;
            for(int i = 0; i < word.size(); ++i) {
                if(curr->m_next[word[i] - 'a'] == nullptr) {
                    curr->m_nex[word[i] - 'a'] = new TrieNode();
                }
                curr = curr->m_nex[word[i] - 'a'];
            }
            curr->m_wordEnd = true;
        }
    };
    
    struct Pos{
        int m_x;
        int m_y;
        Pos() = default;
        Pos(int x, int y) : m_x(x), m_y(y) {}
    };
    
    int m_xMoves = {-1, 0, 1, 0};
    int m_yMoves = {0, 1, 0, -1};
    int m_rowSize;
    int m_colSize;
    
    bool isValid(int i, int j) {
        return (-1 < i && i < m_rowSize && -1 < j && j < m_colSize);
    }
    
    int getKey(int i, int j) {
        return i * m_colSize + j;
    }
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        m_rowSize = board.size();
        if(m_rowSize == 0) return {};
        m_colSize = board[0].size();
        if(m_colSize == 0) return {};

        Trie t;
        int minLen = INT_MAX;
        int maxLen = INT_MIN;
        for(const auto& word : words) {
            t.insert(word);
            minLen = std::min(minLen, word.size());
            maxLen = std::max(maxLen, word.size());
        }
            
        std::vector<std::string> result;
        for(int i = 0; i < m_rowSize; ++i) {
            for(int j = 0; j < m_colSize; ++j) {
                std::queue<Pos> q;
                q.push(Pos(i, j));
                std::unordered_set<int> visited;
                visited.insert(getKey(i, j));
                std::string word(board[i][j]);
                while(!q.empty()) {
                    bool proceed = false;
                    const auto& curr = q.front();
                    q.pop();
                    word += curr;
                    if(word.size() >= minLen && word.size() <= maxLen) {
                        if(t.search(word)) {
                            result.push_back(word);
                        } else {
                            proceed = true;
                        }
                    } else if(word.size() < minLen){
                        if(t.startWith(word)) {proceed = true;}
                        else {word.pop_back();}
                    } 
                    
                    if(proceed) {
                        for(int k = 0; k < 4; ++k) {
                            Pos next(pos.m_x + m_xMoves[k], pos.m_y + m_yMoves[k]);
                            if(!isValid(next)) continue;
                            if(visited.count(word)) continue;
                            q.push(next);
                            visited.insert(getKey(next.m_x, next.m_y));
                        }
                    }
                }
            }
        }
    }
};