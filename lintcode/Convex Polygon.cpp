class Solution {
private:
    struct Vector {
        int m_x;
        int m_y;
        Vector() = default;
        Vector(int x, int y) : m_x(x), m_y(y) {}
    };

public:
    /**
     * @param point: a list of two-tuples
     * @return: a boolean, denote whether the polygon is convex
     */
    bool isConvex(vector<vector<int>> &point) {
        // sort by x first, and then iterate through the points.
        // the y should increase(upper) or decrease(lower) once and then goes
        // to the other direction
        vector<Vector> vectors;
        int len = point.size();
        for(int i = 0; i < len - 1; ++i) {
            vectors.push_back(Vector(point[i+1][0] - point[i][0], point[i+1][1] - point[i][1]));
        }

        vectors.push_back(Vector(point[0][0] - point[len-1][0], point[0][1] - point[len-1][1]));

        len = vectors.size();
        int currProduct = 0;
        int prevProduct = 0;
        for(int i = 0; i < len - 1; ++i) {
            currProduct = vectors[i+1].m_x * vectors[i].m_y - vectors[i+1].m_y * vectors[i].m_x;
            if(currProduct != 0) {
                if(currProduct * prevProduct < 0) return false;
                else prevProduct = currProduct;
            }
        }

        return prevProduct * (vectors[0].m_x * vectors[len-1].m_y - vectors[0].m_y * vectors[len-1].m_x) >= 0;;
    }
};