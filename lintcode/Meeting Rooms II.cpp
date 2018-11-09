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

// Time O(NlogN)
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

// Also Sweep line but using vector + custom comparator. Time is also O(NlogN)
class Solution {
private:
    struct Time{
        int m_time;
        int m_type;
        Time() = default;
        Time(int t, int type) : m_time(t), m_type(type) {}
    };

    struct TimeCompare{
        bool operator()(const Time& t1, const Time& t2) const {
            if(t1.m_time == t2.m_time) return t1.m_type < t2.m_type; // make start type 0 first
            else return t1.m_time < t2.m_time;
        }
    };
public:

    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int len = intervals.size();
        if(len == 0) return 0;

        vector<Time> typeSequence;
        for(const auto& i : intervals) {
            typeSequence.push_back(Time(i.start, 0));
            typeSequence.push_back(Time(i.end, 1));
        }

        std::sort(typeSequence.begin(), typeSequence.end(), TimeCompare());
        int maxRooms = 0;
        int rooms = 0;
        for(const auto& i : typeSequence) {
            if(i.m_type == 0) {
                ++rooms;
            } else {
                --rooms;
            }
            maxRooms = std::max(rooms, maxRooms);
        }

        return maxRooms;
    }
};