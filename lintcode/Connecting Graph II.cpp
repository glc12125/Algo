class ConnectingGraph2 {
public:
    std::vector<int> m_root;
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        m_root.reserve(n+1);
        for (int i = 1; i < n+1; ++i)
            m_root[i] = -1;
    }

    int find(int x) {
        if(m_root[x] < 0) return x;
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
        m_root[rootA] += m_root[rootB];
        m_root[rootB] = rootA;
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        return -m_root[find(a)];
    }
};