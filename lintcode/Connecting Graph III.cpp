class ConnectingGraph3 {
public:
    std::vector<int> m_root;
    int m_connected;
    /*
    * @param n: An integer
    */ConnectingGraph3(int n) {
        m_connected = n;
        m_root.reserve(n+1);
        for (int i = 1; i < n+1; ++i)
            m_root[i] = i;
    }

    int find(int x) {
        if(m_root[x] == x) return x;
        m_root[x] = find(m_root[x]);
        return m_root[x];
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) return;
        m_root[rootA] = rootB;
        --m_connected;
    }

    /*
     * @return: An integer
     */
    int query() {
        return m_connected;
    }
};