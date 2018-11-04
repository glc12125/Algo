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
    void appendInterval(vector<Interval>& result, const Interval& interval) {
        if(result.empty()) {
            result.push_back(interval);
            return;
        }
        auto& last = result.back();
        if(last.end < interval.start) {
            result .push_back(interval);
            return;
        }

        last.end = std::max(last.end, interval.end);
    }
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        int m = list1.size();
        int n = list2.size();
        if(m == 0 && n == 0) return {};
        if(m == 0) return list2;
        if(n == 0) return list1;

        int i = 0;
        int j = 0;
        vector<Interval> result;
        while(i < m && j < n) {
            if(list1[i].start < list2[j].start) {
                appendInterval(result, list1[i++]);
            } else {
                appendInterval(result, list2[j++]);
            }
        }

        while(i < m) {
            appendInterval(result, list1[i++]);
        }
        while(j < n) {
            appendInterval(result, list2[j++]);
        }

        return result;
    }
};