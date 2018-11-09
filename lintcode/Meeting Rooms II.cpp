/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int len = intervals.size();
        if(len == 0) return 0;

        map<int, int> typeSequence;
        for(const auto& i : intervals) {
            ++typeSequence[i.start];
            --typeSequence[i.end];
        }

        int maxRooms = 0;
        int rooms = 0;
        for(const auto& i : typeSequence) {
            rooms += i.second;
            maxRooms = std::max(rooms, maxRooms);
        }

        return maxRooms;
    }
};