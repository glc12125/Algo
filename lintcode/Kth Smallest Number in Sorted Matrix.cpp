// time O(klogk) Space O(k)
class Solution {
private:
    int m_xMoves[2] = {0, 1};
    int m_yMoves[2] = {1, 0};

    bool isValid(int rowSize, int colSize, int i, int j) {
        return (i < rowSize && j < colSize);
    }

    int getKey(int colSize, int i, int j) {
        return i * colSize + j;
    }

    struct Element {
        int m_x;
        int m_y;
        int m_val;
        Element () = default;
        Element(int x, int y, int val) : m_x(x), m_y(y), m_val(val) {}
    };

    struct ValueGreater{
        bool operator()(const Element& e1, const Element& e2) const {
            return e1.m_val > e2.m_val;
        }
    };

public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rowSize = matrix.size();
        if(rowSize == 0) return -1;
        int colSize = matrix[0].size();
        if(colSize == 0) return - 1;

        if(k > rowSize * colSize) return -1;
        std::priority_queue<Element, std::vector<Element>, ValueGreater > orderedContainer;
        std::unordered_set<int> visited;

        orderedContainer.push(Element(0, 0, matrix[0][0]));
        visited.insert(getKey(colSize, 0, 0));

        for(int i = 0; i < k - 1; ++i) {
            auto curr = orderedContainer.top();
            orderedContainer.pop();
             for(int j = 0; j < 2; ++j) {
                auto nextX = curr.m_x + m_xMoves[j];
                auto nextY = curr.m_y + m_yMoves[j];
                if(!isValid(rowSize, colSize, nextX, nextY) || visited.count(getKey(colSize, nextX, nextY))) continue;
                auto next = Element(nextX, nextY, matrix[nextX][nextY]);
                orderedContainer.push(next);
                visited.insert(getKey(colSize, nextX, nextY));
             }
        }

        return orderedContainer.top().m_val;
    }
};

/*
sorted matrix 的两个性质：(1) 每一行是升序 (2) 每一列是升序
方法一的countLessEqual函数，只利用了性质(1)对行做二分，那能不能把性质(2)也利用起来呢?
答案是可以的，过程如下：
以矩阵右上角的点做为起点，
如果该点 <= value, 那么这一行的数都 <= value，计入cnt，i++
如果该点 > value，那么这一列都是 > value , 舍弃这一列，j--
对更新后的点重复上述操作，时间复杂度优化到O(n)

               k = O(1)    k = O(n)     k = O(n^2)
方法二（n）      n           n            n
方法三 (klogk） logn        n * logn     n^2 * logn^2
*/
class Solution {
private:
    int getLTE(const vector<vector<int>> &matrix, int target) {
        int num = 0;
        int n = matrix.size();
        int i = 0;
        int j = n - 1;
        while(i < n && j >-1) {
            if(matrix[i][j] <= target) {
                num += j + 1;
                ++i;
            } else {
                --j;
            }
        }
        return num;
    }
public:
    /**
     * @param matrix: List[List[int]]
     * @param k: a integer
     * @return: return a integer
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        if(n == 0) return -1;

        int l = matrix[0][0];
        int h = matrix[n - 1][n - 1];
        while (l + 1 < h) {
            int mid = l + (h - l) / 2;
            if (getLTE(matrix, mid) >= k) {
                h = mid;
            } else {
                l = mid;
            }
        }

        if (getLTE(matrix, l) >= k) {
            return l;
        }

        return h;
    }
};