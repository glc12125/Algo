/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
private:
    void serializeHelper(TreeNode * node, std::string& result) {
        if(node == nullptr) {
            result += "null,";
            return;
        }
        result += std::to_string(node->val) + ',';
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    void deserializeHelper(TreeNode *& node, const std::string& value, std::queue<TreeNode*>& q) {
        //std::cout << "value: '" << value << "'\n";
        //for (auto c : value) std::cout << c << ",";
        if(value != std::string("null")) {
            //std::cout << "\nbefore stoi, value: '" << value << "'\n";
            int val = std::stoi(value);
            node = new TreeNode(val);
            q.push(node);
        } else {
            node = nullptr;
        }
    }
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        std::string result("{");
        serializeHelper(root, result);

        /*std::queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(curr != nullptr) {
                result += std::to_string(curr->val) + ',';
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result += "null,";
            }
        }*/

        result[result.size() - 1] = '}';
        std::cout << "result: " << result << "\n";
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        //std::cout << "The data: " << data << ", size: " << data.size() << "\n";
        std::queue<TreeNode *> q;
        data = data.substr(1, data.size()-2);
        int startPos = 0;
        int endPos = data.find(',', startPos);
        TreeNode * curr = nullptr;
        TreeNode * root = nullptr;
        if(endPos != std::string::npos) {
            std::string current = data.substr(startPos, endPos - startPos);
            deserializeHelper(root, current, q);
            startPos = endPos + 1;
        }
        while(!q.empty()) {
            endPos = data.find(',', startPos);
            curr = q.front();
            q.pop();
            if(endPos != std::string::npos) {
                std::string left = data.substr(startPos, endPos - startPos);
                deserializeHelper(curr->left, left, q);
                startPos = endPos + 1;
                endPos = data.find(',', startPos);
                std::string right = data.substr(startPos, endPos - startPos);
                deserializeHelper(curr->right, right, q);
                startPos = endPos + 1;
            } else {
                break;
            }
        }

        return root;
    }
};