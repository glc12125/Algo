/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
private:
    void dfs(TrieNode* parent, const string& data, int& index) {
        int len = data.size();
        if(index == len) return;

        if(data[index] == '>') {
            ++index;
            return;
        }

        // skip the first '<'
        if(data[index] == '<') {
            ++index;
        }

        if(index < len && data[index] >= 'a' && data[index] <= 'z') {
            char c = data[index];
            parent->children[c] = new TrieNode();
            ++index;
            dfs(parent->children[c], data, index);
        }
        dfs(parent, data, index);
    }
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        string result = "<";
        for(auto it : root->children) {
            if(it.second != nullptr) {
                result += it.first + serialize(it.second);
            }
        }
        result += ">";
        //std::cout << result << "\n";
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        TrieNode* root = new TrieNode();
        int index = 0;
        dfs(root, data, index);
        return root;
    }
};
