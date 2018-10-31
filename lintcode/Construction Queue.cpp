// DFS timed out
class Solution {
private:
    struct SegmentTreeNode {
        int m_start;
        int m_end;
        int m_count;
        SegmentTreeNode* m_left;
        SegmentTreeNode* m_right;
        SegmentTreeNode(int start, int end, int count) :
                m_start(start), m_end(end), m_count(count),
                m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode * build(const std::unordered_set<int> &A, int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, 0);
        if(start == end) {
            if(A.count(start)) root->m_count = 1;
            return root;
        }

        int mid = (start + end) / 2;
        root->m_left = build(A, start, mid);
        root->m_right = build(A, mid + 1, end);

        root->m_count = 0;
        if(root->m_left != nullptr)  root->m_count += root->m_left->m_count;
        if(root->m_right != nullptr)  root->m_count += root->m_right->m_count;
        return root;
    }

    int query(SegmentTreeNode * root, int start, int end) {
        if(root == nullptr || start > end) return 0;

        if(start <= root->m_start && end >= root->m_end) return root->m_count;

        int leftCount = 0;
        int rightCount = 0;
        int mid = (root->m_start + root->m_end) / 2;
        if(start <= mid) {
            if(end <= mid) {
                leftCount = query(root->m_left, start, end);
            } else {
                leftCount = query(root->m_left, start, mid);
            }
        }

        if(end > mid) {
            if(start > mid) {
                rightCount = query(root->m_right, start, end);
            } else {
                rightCount = query(root->m_right, mid + 1, end);
            }
        }

        return leftCount + rightCount;
    }

    void modify(SegmentTreeNode * root, int num, int count) {
        if(root == nullptr) return;
        if(root->m_start == num && root->m_end == num) {
            root->m_count = count;
            return;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(num <= mid) {
            modify(root->m_left, num, count);
        }
        if(num > mid) {
            modify(root->m_right, num, count);
        }

        root->m_count = root->m_left->m_count + root->m_right->m_count;
    }

    void dfs(const vector<int> &arr1, const vector<int> &arr2, std::unordered_set<int>& chosen, int min, int max, std::vector<int>& result) {
        //std::cout  << "chosen.size(): " << chosen.size() << ", Current result:\n";
        //for(auto i : result) std::cout << i << " ";
        //std::cout << "\n";
        if(result.size() == arr1.size()) {
            m_answer = result;
            return;
        }
        //std::cout << "m_answer.empty(): " << m_answer.empty() << "\n";
        if(!m_answer.empty()) return;

        int len = arr1.size();
        for(int i = 0; i < len; ++i) {
            if(!check(arr1, arr2, i, chosen, min, max, result)) continue;
            chosen.insert(arr1[i]);
            result.push_back(arr1[i]);
            dfs(arr1, arr2, chosen, std::min(min, arr1[i]), std::max(max, arr1[i]), result);
            result.pop_back();
            chosen.erase(arr1[i]);
        }
    }

    bool check(const vector<int> &arr1, const vector<int> &arr2, int candidateIndex, std::unordered_set<int>& chosen, int min, int max, const std::vector<int>& result){
        if(chosen.count(arr1[candidateIndex])) return false;
        int smallerCounter = arr2[candidateIndex];
        if(result.size() < smallerCounter) return false;

        // build SegmentTreeNode
        //std::cout << "candidateIndex: " << candidateIndex << ", building tree [" << min << ", " << max << "]\n";
        //std::cout  << "chosen.size(): " << chosen.size() << ", Current result:\n";
        //for(auto i : result) std::cout << i << " ";
        //std::cout << "\n";
        SegmentTreeNode * root = build(chosen, min, max);
        int actualSmaller = query(root, min, arr1[candidateIndex] - 1);
        /*int actualSmaller = 0;
        for(auto i : result) {
            if(i < arr1[candidateIndex]) {
                if(++actualSmaller > smallerCounter) return false;
            }
        }*/
        return actualSmaller == smallerCounter;
    }

    std::vector<int> m_answer;
public:
    /**
     * @param n: The array sum
     * @param arr1: The size
     * @param arr2: How many numbers small than itself
     * @return: The correct array
     */
    vector<int> getQueue(int n, vector<int> &arr1, vector<int> &arr2) {
        std::vector<int> result;
        if(arr1.size() == 0 || arr2.size() == 0 || arr1.size() != n || arr2.size() != n) return result;
        std::unordered_set<int> chosen;
        std::vector<int> answer;
        int min = INT_MAX;
        int max = INT_MIN;
        dfs(arr1, arr2, chosen, min, max, answer);
        return m_answer;
    }
};


// Segment Tree version, time O(nlogn)
class Solution {
private:
    struct SegmentTreeNode {
        int m_start;
        int m_end;
        int m_count;
        SegmentTreeNode* m_left;
        SegmentTreeNode* m_right;
        SegmentTreeNode(int start, int end, int count) :
                m_start(start), m_end(end), m_count(count),
                m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode * build(int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, 1);
        if(start == end)  return root;

        int mid = (start + end) / 2;
        root->m_left = build(start, mid);
        root->m_right = build(mid + 1, end);

        root->m_count = 0;
        if(root->m_left != nullptr)  root->m_count += root->m_left->m_count;
        if(root->m_right != nullptr)  root->m_count += root->m_right->m_count;
        return root;
    }

    int query(SegmentTreeNode * root, int target) {
        if(root == nullptr) return 0;

        if(root->m_start == root->m_end) {
            root->m_count = 0;
            return root->m_start;
        }

        int mid = (root->m_start + root->m_end) / 2;
        int res = 0;

        if(target <= root->m_left->m_count) {
            res = query(root->m_left, target);
        } else {
            res = query(root->m_right, target - root->m_left->m_count);
        }

        root->m_count = 0;
        if(root->m_left != nullptr)  root->m_count += root->m_left->m_count;
        if(root->m_right != nullptr)  root->m_count += root->m_right->m_count;
        return res;
    }

    struct Node{
        int m_num;
        int m_smallerCount;
        Node () = default;
        Node(int num, int count) : m_num(num), m_smallerCount(count) {}
    };

    struct NodeCompare{
        bool operator()(const Node& n1, const Node& n2) const {
            return n1.m_num > n2.m_num;
        }
    };
public:
    /**
     * @param n: The array sum
     * @param arr1: The size
     * @param arr2: How many numbers small than itself
     * @return: The correct array
     */
    vector<int> getQueue(int n, vector<int> &arr1, vector<int> &arr2) {
        std::vector<int> result;
        if(arr1.size() == 0 || arr2.size() == 0 || arr1.size() != n || arr2.size() != n) return result;

        int len = arr1.size();
        std::vector<Node> nodes(len);
        for(int i = 0; i < len; ++i) {
            nodes[i] = Node(arr1[i], arr2[i]);
        }

        std::sort(nodes.begin(), nodes.end(), NodeCompare());

        SegmentTreeNode* root = build(1, n);
        result.resize(n);
        for(auto node : nodes) {
            int pos = query(root, node.m_smallerCount + 1);
            result[pos - 1] = node.m_num;
        }
        return result;
    }
};