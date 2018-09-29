class MyCalendarThree {
private:
    std::map<int, int> m_bookings;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int cnt = 0;
        m_bookings[start]++;
        m_bookings[end]--;
        int max = 0;
        for (const auto& it : m_bookings) {
            cnt += it.second;
            max = std::max(max, cnt);
        }
        return max;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */