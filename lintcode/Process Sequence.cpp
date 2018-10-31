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
     * @param logs: Sequence of processes
     * @param queries: Sequence of queries
     * @return: Return the number of processes
     */
    vector<int> numberOfProcesses(vector<Interval> &logs, vector<int> &queries) {
        std::map<int, int> counter;
        for(const auto& interval : logs) {
            ++counter[interval.start];
            --counter[interval.end];
        }

        int len = queries.size();
        std::vector<int> result(len, 0);
        for(int i = 0; i < len; ++i) {
            int cnt = 0;
            for(auto c : counter) {
                if(c.first > queries[i]) break;
                cnt += c.second;
            }
            result[i] = cnt;
        }
        return result;
    }
};


// Time O(nklognk)
class Solution {
private:
    struct IntervalCompare{
        bool operator()(const Interval& i1, const Interval& i2) const {
            return i1.start < i2.start;
        }
    };
public:
    /**
     * @param logs: Sequence of processes
     * @param queries: Sequence of queries
     * @return: Return the number of processes
     */
    vector<int> numberOfProcesses(vector<Interval> &logs, vector<int> &queries) {
        std::vector<Interval> sequences;

        for(const auto& i : logs) {
            sequences.push_back(Interval(i.start, 0));
            sequences.push_back(Interval(i.end, 1));
        }

        for(auto i : queries) {
            sequences.push_back(Interval(i, 2));
        }

        std::sort(sequences.begin(), sequences.end(), IntervalCompare());

        std::unordered_map<int, int> counters;
        int cnt = 0;
        for(const auto& s : sequences) {
            if(s.end == 0) ++cnt;
            else if (s.end == 1) --cnt;
            counters[s.start] = cnt;
        }
        int len = queries.size();
        std::vector<int> result(len, 0);
        for(int i = 0; i < len; ++i) {
            result[i] = counters[queries[i]];
        }
        return result;
    }
};