class Solution {
private:
    struct BuildingPoint {
        int m_location;
        int m_type;
        int m_height;
        BuildingPoint() = default;
        BuildingPoint(int location, int type, int height) : m_location(location), m_type(type), m_height(height) {}
    };

    struct BuildingPointCompare {
        bool operator()(const BuildingPoint& b1, const BuildingPoint& b2) const {
            if(b1.m_location == b2.m_location) {
                if(b1.m_type == b2.m_type) {
                    return b1.m_height < b2.m_height;
                } else {
                    return b1.m_type < b2.m_type;
                }
            }
            else return b1.m_location < b2.m_location;
        }
    };
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {

        if(buildings.empty()) return {};
        vector<BuildingPoint> points;
        for(const auto& building : buildings) {
            points.push_back(BuildingPoint(building[0], 0, building[2]));
            points.push_back(BuildingPoint(building[1], 1, building[2]));
        }

        std::sort(points.begin(), points.end(), BuildingPointCompare());

        vector<vector<int>> result;

        multiset<int, std::greater<int>> heights;
        vector<int> currentLine(3);
        for(const auto& point : points) {
            if(point.m_type == 0) { // start
                if(!heights.empty()) {
                    if(point.m_height > *heights.begin()){
                        currentLine[1] = point.m_location;
                        if(currentLine[0] < currentLine[1]) result.push_back(currentLine);
                        currentLine[0] = point.m_location;
                    }
                } else {
                    currentLine[0] = point.m_location;
                }
                heights.insert(point.m_height);
                currentLine[2] = *heights.begin();
            } else { // end
                heights.erase(heights.find(point.m_height));
                if(heights.empty()) {
                    currentLine[1] = point.m_location;
                    if(currentLine[0] < currentLine[1])result.push_back(currentLine);
                } else if(*heights.begin() < currentLine[2]) {
                    currentLine[1] = point.m_location;
                    if(currentLine[0] < currentLine[1])result.push_back(currentLine);
                    currentLine[0] = point.m_location;
                    currentLine[2] = *heights.begin();
                }
            }
        }

        return result;
    }
};