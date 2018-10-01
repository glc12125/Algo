class Memcache {
private:
    struct Entry
    {
        int value;
    	int expiry;
    	Entry(int v, int e) : value(v), expiry(e) {}
    	Entry() = default;
    };
    int defaultValue = 2147483647;
    std::unordered_map<int, Entry> m_cache; // maps to (value, currTime)

public:
    Memcache() {
        // do intialization if necessary
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: An integer
     */
    int get(int curtTime, int key) {
        auto itr = m_cache.find(key);
        if(itr == m_cache.end()) return defaultValue;
        int expiry = itr->second.expiry;
        if(expiry < 0 || curtTime < expiry) return itr->second.value;
        else return defaultValue;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param value: An integer
     * @param ttl: An integer
     * @return: nothing
     */
    void set(int curtTime, int key, int value, int ttl) {
        auto entry = Entry(value, curtTime + ttl);
        if(ttl == 0) entry.expiry = -1;
        m_cache[key] = entry;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: nothing
     */
    void del(int curtTime, int key) {
        m_cache.erase(key);
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int incr(int curtTime, int key, int delta) {
        auto itr = m_cache.find(key);
        if(itr == m_cache.end()) return defaultValue;

        int expiry = itr->second.expiry;
        if(expiry < 0 || curtTime < expiry) {
            itr->second.value += delta;
			return itr->second.value;
        }
        else return defaultValue;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int decr(int curtTime, int key, int delta) {
        return incr(curtTime, key, -delta);
    }
};