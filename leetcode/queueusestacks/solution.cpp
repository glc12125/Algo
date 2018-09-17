#include <stack>
#include <iostream>

using namespace std;

class Queue
{
    stack<int> d_s1;
    stack<int> d_s2;

public:
    // Push element x to the back of queue.
    void push(int x)
    {
        d_s2.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
       if (d_s1.empty()) {
            if (d_s2.empty()) {
                return ;
            } else {
                while (!d_s2.empty()) {
                    d_s1.push(d_s2.top());
                    d_s2.pop();
                }
            }
       } 
       d_s1.pop();

    }

    // Get the front element.
    int peek(void)
    {
       if (d_s1.empty()) {
            if (d_s2.empty()) {
                return 0;
            } else {
                while (!d_s2.empty()) {
                    d_s1.push(d_s2.top());
                    d_s2.pop();
                }
            }
       } 

       return d_s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return d_s1.empty() && d_s2.empty();
    }
};
