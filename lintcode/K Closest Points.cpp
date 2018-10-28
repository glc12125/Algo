/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
private:
    struct DistPoint {
        float m_dist;
        Point m_point;
        DistPoint () = default;
        DistPoint(float dist, const Point& point) : m_dist(dist), m_point(point) {}
    };

    struct PointCompare {
        bool operator()(const DistPoint& p1, const DistPoint& p2) const {
            if(p1.m_dist != p2.m_dist) return p1.m_dist < p2.m_dist;
            if(p1.m_point.x != p2.m_point.x) return p1.m_point.x < p2.m_point.x;
            if(p1.m_point.y != p2.m_point.y) return p1.m_point.y < p2.m_point.y;
        }
    };

    std::priority_queue<DistPoint, std::vector<DistPoint>, PointCompare> m_q;

    float getDistanceSquare(const Point& p1, const Point& p2) {
        float xDiff = (p1.x - p2.x);
        float yDiff = (p1.y - p2.y);
        return xDiff * xDiff + yDiff * yDiff;
    }
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        for(const auto& p : points) {
            m_q.push(DistPoint(getDistanceSquare(p, origin), p));
            if(m_q.size() > k) m_q.pop();
        }

        std::vector<Point> result;
        while(!m_q.empty()) {
            auto distPoint = m_q.top();
            m_q.pop();
            result.push_back(distPoint.m_point);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};