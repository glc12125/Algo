/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
private:
    void getPath(ParentTreeNode * root, int target) {
        if(root == nullptr) return;

        std::vector<int> path;
        getSum(root, nullptr, path, target);

        getPath(root->left, target);
        getPath(root->right, target);
    }

    void getSum(ParentTreeNode * root, ParentTreeNode * parent, std::vector<int> path, int target) {
        if(root == nullptr) return;
        path.push_back(root->val);
        target -= root->val;

        if(target == 0) {
            m_results.push_back(path);
        }

        if (root->parent != nullptr && root->parent != parent)
            getSum(root->parent, root, path, target);

        if (root->left != nullptr && root->left  != parent)
            getSum(root->left, root, path, target);

        if (root->right != nullptr && root->right != parent)
            getSum(root->right, root, path, target);
    }
    std::vector<std::vector<int> > m_results;
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
        getPath(root, target);
        return m_results;
    }
};

// Follow up, do not use parent pointer
class Solution {
private:
    struct ResultType{
        std::vector<std::vector<int> > m_upwardPaths;
        std::vector<std::vector<int> > m_downwardPaths;
    };

    ResultType getPath(ParentTreeNode * root, int target) {
        if(root == nullptr) return ResultType();

        auto leftResult = getPath(root->left, target);
        auto rightResult = getPath(root->right, target);

        if(root->val == target) m_results.push_back({root->val});

        // check sum and add results
        // From right to left
        {
            std::vector<std::vector<int> > upwards(rightResult.m_upwardPaths.begin(), rightResult.m_upwardPaths.end());
            upwards.push_back({});
            std::vector<std::vector<int> > downwards(leftResult.m_downwardPaths.begin(), leftResult.m_downwardPaths.end());
            downwards.push_back({});
            for(const auto& rightU : upwards) {
                for(const auto& leftD : downwards) {
                    if(rightU.size() != 0 || leftD.size() != 0) {
                        std::vector<int> answer(rightU.begin(), rightU.end());
                        answer.push_back(root->val);
                        answer.insert(answer.end(), leftD.begin(), leftD.end());
                        if(std::accumulate(answer.begin(), answer.end(), 0) == target) {
                            m_results.push_back(answer);
                        }
                    }
                }
            }
        }

        // From left to right
        {
            std::vector<std::vector<int> > upwards(leftResult.m_upwardPaths.begin(), leftResult.m_upwardPaths.end());
            upwards.push_back({});
            std::vector<std::vector<int> > downwards(rightResult.m_downwardPaths.begin(), rightResult.m_downwardPaths.end());
            downwards.push_back({});
            for(const auto& leftU : upwards) {
                for(const auto& rightD : downwards) {
                    if(leftU.size() != 0 || rightD.size() != 0) {
                        std::vector<int> answer(leftU.begin(), leftU.end());
                        answer.push_back(root->val);
                        answer.insert(answer.end(), rightD.begin(), rightD.end());
                        if(std::accumulate(answer.begin(), answer.end(), 0) == target) {
                            m_results.push_back(answer);
                        }
                    }
                }
            }
        }

        ResultType result;
        // populated upwardPaths in results
        result.m_downwardPaths.insert(result.m_downwardPaths.end(), leftResult.m_downwardPaths.begin(), leftResult.m_downwardPaths.end());
        result.m_downwardPaths.insert(result.m_downwardPaths.end(), rightResult.m_downwardPaths.begin(), rightResult.m_downwardPaths.end());
        for(auto & path : result.m_downwardPaths) {
            path.insert(path.begin(), root->val); // slow...
        }
        result.m_downwardPaths.push_back({root->val});
        // populated downwardPaths in results
        result.m_upwardPaths.insert(result.m_upwardPaths.end(), leftResult.m_upwardPaths.begin(), leftResult.m_upwardPaths.end());
        result.m_upwardPaths.insert(result.m_upwardPaths.end(), rightResult.m_upwardPaths.begin(), rightResult.m_upwardPaths.end());
        for(auto & path : result.m_upwardPaths) {
            path.push_back(root->val);
        }
        result.m_upwardPaths.push_back({root->val});

        return result;
    }

    std::vector<std::vector<int> > m_results;
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
        getPath(root, target);
        return m_results;
    }
};