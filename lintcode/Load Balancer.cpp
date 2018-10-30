class LoadBalancer {
private:
    std::unordered_map<int, int> m_indexes;
    std::vector<int> m_servers;
public:
    LoadBalancer() {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        if(m_indexes.count(server_id)) return;
        m_indexes[server_id] = m_servers.size();
        m_servers.push_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        if(m_indexes.count(server_id) == 0) return;
        auto index = m_indexes[server_id];
        int lastIndex = m_servers.size() - 1;
        m_indexes[m_servers[lastIndex]] = index;
        m_servers[index] = m_servers[lastIndex];
        m_servers.pop_back();
        m_indexes.erase(server_id);
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        int randomIndex = (int)std::rand() % (m_servers.size());
        return m_servers[randomIndex];
    }
};