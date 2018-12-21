class HeartBeat {
private:
    int m_k;
    unordered_map<string, set<int>> m_ipPings;

public:
    HeartBeat() {
        // do intialization if necessary
    }

    /*
     * @param slaves_ip_list: a list of slaves'ip addresses
     * @param k: An integer
     * @return: nothing
     */
    void initialize(vector<string> &slaves_ip_list, int k) {
        m_k = k;
        for(const auto& ip : slaves_ip_list) {
            m_ipPings[ip];
        }
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @param slave_ip: the ip address of the slave server
     * @return: nothing
     */
    void ping(int timestamp, string &slave_ip) {
        if(m_ipPings.count(slave_ip)) {
            m_ipPings[slave_ip].insert(timestamp);
        }
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @return: a list of slaves'ip addresses that died
     */
    vector<string> getDiedSlaves(int timestamp) {
        int startTime = timestamp - m_k * 2 + 1;
        vector<string> died;
        for(auto& ipTimestamps : m_ipPings) {
            auto it = ipTimestamps.second.lower_bound(startTime);
            if(it == ipTimestamps.second.end() && startTime > 0) {
                died.emplace_back(ipTimestamps.first);
            }
        }

        return died;
    }
};