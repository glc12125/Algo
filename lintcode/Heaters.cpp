class Solution {
private:
    int findRadius(const std::vector<int>& heaters, int house){
        int end = heaters.size() - 1;
        int start = 0;
        while (start + 1< end) {
            int mid = (start + end)/ 2;
            if(house == heaters[mid]) return 0;
            else if(house < heaters[mid]) end = mid;
            else start = mid;
        }

        return std::min(abs(heaters[end] - house),
                        abs(house - heaters[start]));
    }
public:
    /**
     * @param houses: positions of houses
     * @param heaters: positions of heaters
     * @return: the minimum radius standard of heaters
     */
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        std::sort(heaters.begin(), heaters.end());
        int radius = -1;
        for(auto house : houses) {
            int closestRadius = findRadius(heaters, house);
            if(radius < closestRadius) radius = closestRadius;
        }
        return radius;
    }
};