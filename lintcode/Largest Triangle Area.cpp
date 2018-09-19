// Use Shoelace Formula: https://en.wikipedia.org/wiki/Shoelace_formula
class Solution {
private:
    double calculateArea(vector<int> A, vector<int> B, vector<int> C) {
        return 0.5 * std::abs(A[0]*B[1] + B[0]*C[1] + C[0]*A[1] -
                              A[1]*B[0] - B[1]*C[0] - C[1]*A[0]);
    }
public:
    /**
     * @param points: List[List[int]]
     * @return: return a double
     */
    double largestTriangleArea(vector<vector<int>> &points) {
        int N = points.size();
        double area = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                for(int k = j + 1; k < N; ++k) {
                    area = std::max(calculateArea(points[i], points[j], points[k]), area);
                }
            }
        }
        return area;
    }
};