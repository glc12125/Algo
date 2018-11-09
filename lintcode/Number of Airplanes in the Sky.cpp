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
private:
    struct Time{
        int m_time;
        int m_type;
        Time() = default;
        Time(int t, int type) : m_time(t), m_type(type) {}
    };

    struct TimeCompare{
        bool operator()(const Time& t1, const Time& t2) const {
            if(t1.m_time == t2.m_time) return t1.m_type > t2.m_type; // make start type 0 first
            else return t1.m_time < t2.m_time;
        }
    };
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int len = airplanes.size();
        if(len == 0) return 0;

        vector<Time> typeSequence;
        for(const auto& i : airplanes) {
            typeSequence.push_back(Time(i.start, 0));
            typeSequence.push_back(Time(i.end, 1));
        }

        std::sort(typeSequence.begin(), typeSequence.end(), TimeCompare());
        int maxFlights = 0;
        int flights = 0;
        for(const auto& i : typeSequence) {
            if(i.m_type == 0) {
                ++flights;
            } else {
                --flights;
            }
            maxFlights = std::max(flights, maxFlights);
        }

        return maxFlights;
    }
};