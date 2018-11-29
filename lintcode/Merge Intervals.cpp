/**
 * Definition of Interval:
 * struct Interval {
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [] (const Interval& i1, const Interval& i2)
            {
                return (i1.start < i2.start);
            }
        );
        // write your code here
        int prevStart = INT_MIN;
        int prevEnd = INT_MIN;
        vector<Interval> result;
        for(auto& interval : intervals) {
            if(interval.start > prevEnd) {
                result.push_back(interval);
                prevStart = interval.start;
                prevEnd = interval.end;
            } else {
                auto last = result.back();
                result.pop_back();
                prevStart = last.start;
                prevEnd = max(last.end, interval.end);
                result.emplace_back(prevStart, prevEnd);
            }
        }

        return result;
    }

};