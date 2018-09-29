class MyCalendarTwo {
private:
    
    struct Booking {
        int start, end;
        Booking(int s, int e) : start(s), end(e) {}
    };
    
    struct BookingCompare {
      bool operator() (const Booking& lhs, const Booking& rhs) const
      {
          return lhs.start<rhs.start || ((lhs.start >= rhs.start) && (lhs.end < rhs.end));
      }
    };

    std::set<Booking, BookingCompare> m_overBooked;
    std::set<Booking, BookingCompare> m_booked;
    

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto& booking : m_overBooked) {
            if(booking.start >= end || booking.end <= start) continue;
            else return false;
        }
        
        for(auto& booking : m_booked) {
            if(booking.start >= end || booking.end <= start) continue;
            else m_overBooked.insert(Booking(std::max(start, booking.start), std::min(end, booking.end)));
        }

        m_booked.insert(Booking(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */