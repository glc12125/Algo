class WebLogger {
private:
    struct TimeHit {
        int m_timestamp;
        int m_hit;
        TimeHit() = default;
        TimeHit(int timestamp, int hit) : m_timestamp(timestamp), m_hit(hit) {}
    };

    deque<TimeHit> m_timeHit;
    int m_counter;
public:
    WebLogger() {
        m_counter = 0;
    }

    /*
     * @param timestamp: An integer
     * @return: nothing
     */
    void hit(int timestamp) {
        ++m_counter;
        if(!m_timeHit.empty() && m_timeHit.back().m_timestamp == timestamp) {
            ++m_timeHit.back().m_hit;
        } else {
            m_timeHit.push_back(TimeHit(timestamp, 1));
        }
    }

    /*
     * @param timestamp: An integer
     * @return: An integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        while(!m_timeHit.empty() && m_timeHit.front().m_timestamp + 300 <= timestamp) {
            m_counter -= m_timeHit.front().m_hit;
            m_timeHit.pop_front();
        }
        return m_counter;
    }
};