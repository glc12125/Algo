/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
private:
    struct AvgRecord {
        std::priority_queue<int, std::vector<int>, std::greater<int> > m_minQ;
        AvgRecord() = default;
        AvgRecord(int val) {
            m_minQ.push(val);
        }
    };

    std::unordered_map<int, AvgRecord> m_records;

    void addRecord(const Record& r) {
        if(m_records.count(r.id)) {
            auto& avgRecord = m_records[r.id];
            avgRecord.m_minQ.push(r.score);
            if(avgRecord.m_minQ.size() > 5) {
                avgRecord.m_minQ.pop();
            }
        } else {
            m_records[r.id] = AvgRecord(r.score);
        }
    }

    std::map<int, double> getHighFive(){
        std::map<int, double> result;
        for(auto& record : m_records) {
            long sum = 0;
            int count = record.second.m_minQ.size();
            while(!record.second.m_minQ.empty()) {
                sum += record.second.m_minQ.top();
                record.second.m_minQ.pop();
            }
            result[record.first] = (double)sum / count;
        }
        return result;
    }
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        for(const auto& record : results) addRecord(record);
        return getHighFive();
    }
};