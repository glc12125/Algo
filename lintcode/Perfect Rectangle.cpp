class Solution {
private:
    struct Interval {
        int m_start;
        int m_end;
        bool m_edge;
        Interval() = default;
        Interval(int start, int end, bool edge) : m_start(start), m_end(end), m_edge(edge) {}
    };

    struct IntervalCompare{
        bool operator()(const Interval& i1, const Interval& i2) const {
            return i1.m_start < i2.m_start;
        }
    };

    bool checkIntervals(vector<Interval>& row, int xMin, int xMax) {
        int len = row.size();

        sort(row.begin(), row.end(), [](const Interval& a, const Interval& b) {
            return a.m_start < b.m_start;
        });
        for(int i = 1; i < len; ++i) {
            if((!row[i-1].m_edge || !row[i].m_edge) && row[i-1].m_end != row[i].m_start) return false;
        }
        return row[0].m_start == xMin && row.back().m_end == xMax;
    }
public:
    /**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int n = rectangles.size();
        if(n == 0) return false;

        int xMin = INT_MAX;
        int xMax = INT_MIN;
        int yMin = INT_MAX;
        int yMax = INT_MIN;
        for(const auto& line : rectangles) {
            xMin = std::min(xMin, line[0]);
            yMin = std::min(yMin, line[1]);
            xMax = std::max(xMax, line[2]);
            yMax = std::max(yMax, line[3]);
        }

        unordered_map<int, vector<Interval>> rows;
        for(const auto& line : rectangles) {
            int rowStart = line[1];
            int rowEnd = line[3];
            for(int i = rowStart; i <= rowEnd; ++i) {
                if(i == rowStart || i == rowEnd) {
                    rows[i].push_back(Interval(line[0], line[2], true));
                } else {
                    rows[i].push_back(Interval(line[0], line[2], false));
                }
            }
        }

        for(auto& row : rows) {
            if(!checkIntervals(row.second, xMin, xMax)) {
                return false;
            }
        }
        return true;
    }
};