class Solution {
public:
  /**
   * Insert newInterval into intervals.
   * @param intervals: Sorted interval list.
   * @param newInterval: new interval.
   * @return: A new interval list.
   */
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    // write your code here
    vector<Interval> ans;
    int st;
    for (st = 0; st < intervals.size() && intervals[st].start < newInterval.start; st++) {
      ans.push_back(intervals[st]);
    }

    if (!ans.empty() && ans.back().end >= newInterval.start) {
      ans.back().end = max(ans.back().end, newInterval.end);
    } else {
      ans.push_back(newInterval);
     }

    for (int i = st; i < intervals.size(); i++) {
      if (ans.back().end >= intervals[i].start) {
        ans.back().end = max(ans.back().end, intervals[i].end);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
};