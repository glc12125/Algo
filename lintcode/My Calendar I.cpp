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


// Use map version 1, decide when to fail
class MyCalendar {
private:

    map<int, int> m_pointMap;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if(!m_pointMap.empty()) {
            int activeCount = 0;
            int prevPoint = -1;
            for(auto point : m_pointMap) {
                // If meeting has not finished yet, the end point is later than the starting point of current meeting and
                // the start point is earlier than the ending point of current meeting
                if(prevPoint != -1 && end > prevPoint && start < point.first && activeCount > 0) {
                    return false;
                }
                // if meeting has finished,
                if(prevPoint != -1 && start < prevPoint && end > point.first && activeCount == 0) {
                    return false;
                }

                if(point.second == 0) {
                    ++activeCount;
                } else {
                    --activeCount;
                }
                prevPoint = point.first;
            }
            if(m_pointMap.count(start)) {
                if(m_pointMap[start] == 1) {
                    m_pointMap.erase(start);
                }
            } else {
                m_pointMap[start] = 0;
            }

            if(m_pointMap.count(end)) {
                if(m_pointMap[end] == 0) {
                    m_pointMap.erase(end);
                }
            } else {
                m_pointMap[end] = 1;
            }
            return true;
        } else {
            m_pointMap[start] = 0;
            m_pointMap[end] = 1;
            return true;
        }
    }
};

// Use map version 2, decide when to succeed
class MyCalendar {
private:

    map<int, int> m_pointMap;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if(m_pointMap.empty()) {
            m_pointMap[start] = end;
            return true;
        }

        map<int, int>::iterator prev;
        auto next = m_pointMap.lower_bound(start);
        if(next == m_pointMap.end()) prev = --m_pointMap.end();
        else if(next == m_pointMap.begin()) prev = m_pointMap.end();
        else {
            prev = --next;
            ++next;
        }
        if((prev != m_pointMap.end() && prev->second <= start) && (next != m_pointMap.end() && next->first >= end)) {
            m_pointMap[start] = end;
            return true;
        } else if(prev == m_pointMap.end() && m_pointMap.begin()->first >= end) {
            m_pointMap[start] = end;
            return true;
        } else if(next == m_pointMap.end() && (m_pointMap.rbegin())->second <= start) {
            m_pointMap[start] = end;
            return true;
        }

        return false;
    }
};

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