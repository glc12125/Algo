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
    vector<Interval> divideAndConquer(const vector<vector<Interval>> &intervals, int start, int end) {
        if(start == end) return intervals[start];

        int mid = start + (end - start) / 2;
        const auto& first = divideAndConquer(intervals, start, mid);
        const auto& second = divideAndConquer(intervals, mid + 1, end);

        return merge(first, second);
    }

    vector<Interval> merge(const vector<Interval>& first, const vector<Interval>& second) {

        int fLen = first.size();
        int sLen = second.size();
        vector<Interval> result;
        int i = 0;
        int j = 0;
        while( i < fLen && j < sLen) {
            if(first[i].start < second[j].start) append(result, first[i++]);
            else append(result, second[j++]);
        }

        while(i < fLen) append(result, first[i++]);
        while(j < sLen) append(result, second[j++]);
        return result;
    }

    void append(vector<Interval>& result, const Interval& newI) {
        if(result.size() == 0) {
            result.push_back(newI);
            return;
        }

        auto& last = result.back();
        if(last.end < newI.start) {
            result.push_back(newI);
            return;
        }
        last.end = std::max(last.end, newI.end);
    }
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        int len = intervals.size();
        if(len == 0) return {};
        return divideAndConquer(intervals, 0, intervals.size() - 1);
    }
};