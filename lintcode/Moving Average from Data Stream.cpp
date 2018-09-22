// Use a queue, this is less memory friendly
class MovingAverage {
private:
    std::queue<int> m_q;
    int m_size;
    double m_sum;
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        m_size = size;
        m_sum = 0;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        m_q.push(val);
        m_sum += val;
        auto currSize = m_q.size();
        int popped = 0;
        if(currSize > m_size) {
            popped = m_q.front();
            m_q.pop();
        }
        m_sum -= popped;
        return currSize > m_size ? m_sum / m_size : m_sum / currSize; 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */

// Use a rolling vector to mimic a queue

class MovingAverage {
private:
    std::vector<int> m_q;
    int m_size;
    double m_sum;
    int m_count;
private:
    int getIndex(int count) const {
        return count % (m_size);
    }
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        m_size = size;
        m_sum = 0;
        m_count = 0;
        m_q = std::vector<int>(m_size, 0);
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        m_sum += val;
        int popped = 0;
        if(m_count >= m_size) {
            popped = m_q[getIndex(m_count - m_size)];
        }
        m_q[getIndex(m_count)] = val;
        m_sum -= popped;
        ++m_count;
        return m_count > m_size ? m_sum / m_size : m_sum / m_count; 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */