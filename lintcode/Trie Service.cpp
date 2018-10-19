/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and
        // lintcode will print the tree struct.
        return root;
    }

    void insert(string& word, int frequency) {
        TrieNode * node = root;
        for(int i = 0; i < word.size(); ++i) {
            if(node->children.count(word[i]) == 0) {
                node->children[word[i]] = new TrieNode();
            }
            node = node->children[word[i]];
            node->top10.push_back(frequency);
            std::sort(node->top10.begin(), node->top10.end(), [](const int a, const int b) {return a > b; });
            if(node->top10.size() > 10) node->top10.erase(node->top10.begin() + 10, node->top10.end());
        }
    }
};

