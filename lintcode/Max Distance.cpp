class Solution {
private:
    struct TrieNode{
        bool m_binEnd = false;
        //priority_queue<int, vector<int>> m_suffixLenQ;
        int m_maxSuffixLen = 0;
        TrieNode* m_children[2] = {nullptr};
    };

    void insert(TrieNode * root, const string& bin) {
        auto current = root;
        int suffixLen = bin.size();
        for(auto c : bin) {
            auto index = c - '0';
            if(current->m_children[index] == nullptr) {
                current->m_children[index] = new TrieNode();
            }
            current = current->m_children[index];
            current->m_maxSuffixLen = std::max(current->m_maxSuffixLen, suffixLen);
            //current->m_suffixLenQ.push(suffixLen);
            //if(current->m_suffixLenQ.size() > 2) {
            //    current->m_suffixLenQ.pop();
            //}
            --suffixLen;
        }
        current->m_binEnd = true;
    }

    void dfs(TrieNode* root, int& maxLen) {
        if(root == nullptr) {
            return;
        }

        if(root->m_children[0] != nullptr && root->m_children[1] != nullptr) {
            int len = root->m_children[0]->m_maxSuffixLen +
                      root->m_children[1]->m_maxSuffixLen;
            maxLen = std::max(len, maxLen);
        }

        if(root->m_children[0] != nullptr) {
            if(root->m_binEnd) {
                maxLen = std::max(maxLen, root->m_children[0]->m_maxSuffixLen);
            }
            dfs(root->m_children[0], maxLen);
        }

        if(root->m_children[1] != nullptr) {
            if(root->m_binEnd) {
                maxLen = std::max(maxLen, root->m_children[1]->m_maxSuffixLen);
            }
            dfs(root->m_children[1], maxLen);
        }
    }
public:
    /**
     * @param s: the list of binary string
     * @return: the max distance
     */
    int getAns(vector<string> &s) {
        int len = s.size();
        if(len == 0) return 0;

        TrieNode * root = new TrieNode();
        for(const auto& bin : s) {
            insert(root, bin);
        }

        int maxLen = 0;
        dfs(root, maxLen);
        return maxLen;
    }
};