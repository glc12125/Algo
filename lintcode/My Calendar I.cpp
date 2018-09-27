class MyCalendar {
private:

struct Booking {
    int start, end;
    Booking(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

std::vector<Booking> m_bookings;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Booking newBooking(start, end);
        if(m_bookings.size() == 0) {
            m_bookings.push_back(newBooking);
            return true;
        } 
        Booking toBeInserted(start, end);
        int ins_pos = 0;
        for (auto now : m_bookings) {
            if(now.end < newBooking.start) {
                ins_pos++;
            } 
            else if(newBooking.end < now.start) {
            }
            else if((newBooking.start < now.end && now.start <= newBooking.start) || (newBooking.end > now.start && newBooking.start <= now.start)) {
                return false;
            }
            else {
                newBooking.start = std::min(newBooking.start, now.start);
                newBooking.end = std::max(newBooking.end, now.end);
            }
        }

        m_bookings.insert(m_bookings.begin() + ins_pos, toBeInserted);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

// The best solution is to use double linked list, so there shouldn't be a final
// rearrangement of the vector as above

class MyCalendar {
private:

struct Booking {
    int start, end;
    Booking * left;
    Booking * right;
    Booking(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Booking * m_root;


bool insert(Booking* booking, int start, int end) {
    if(start >= booking->end) {
        if(booking->right == nullptr) {
            booking->right = new Booking(start, end);
            return true;
        } else return insert(booking->right, start, end);
    } else if (end <= booking->start) {
        if(booking->left == nullptr) {
            booking->left = new Booking(start, end);
            return true;
        } else return insert(booking->left, start, end);
    } else {
        return false;
    }
}

public:
    MyCalendar() {
        m_root = nullptr;
    }
    
    bool book(int start, int end) {
        if(m_root == nullptr) {
            m_root = new Booking(start, end);
            return true;
        } 

        return insert(m_root, start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */