class Solution {
private:
    struct Num {
        int m_val;
        int m_rIndex;
        int m_index;
        Num () = default;
        Num(int val, int rIndex, int index) : m_val(val), m_rIndex(rIndex), m_index(index) {}
    };

    struct NumCompare {
        bool operator()(const Num& n1, const Num& n2) const {
            return n1.m_val > n2.m_val;
        }
    };
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int Alen = A.size();
        int Blen = B.size();

        if(Alen == 0 && Blen == 0) return 0;

        bool isEven = (Alen + Blen) % 2 == 0;
        int mid = (Alen + Blen) / 2;
        if(Alen == 0) {
            if(isEven) return (B[mid-1] + B[mid]) / 2.0;
            else return B[mid] * 1.0;
        }
        if(Blen == 0) {
            if(isEven) return (A[mid-1] + A[mid]) / 2.0;
            else return A[mid] * 1.0;
        }

        std::priority_queue<Num, std::vector<Num>, NumCompare> q;
        q.push(Num(A[0], 0, 0));
        q.push(Num(B[0], 1, 0));

        double sum = 0;
        double result = 0;
        for(int i = 0; i <= mid; ++i) {
            auto num = q.top();
            q.pop();
            if(isEven) {
                if(i >= mid - 1) sum += num.m_val;
            } else {
                if(i == mid) sum = num.m_val;
            }
            if(num.m_rIndex == 0) {
                if(num.m_index + 1 < Alen) q.push(Num(A[num.m_index + 1], 0, num.m_index + 1));
            } else {
                if(num.m_index + 1 < Blen) q.push(Num(B[num.m_index + 1], 1, num.m_index + 1));
            }
        }

        if(isEven) {
            return sum / 2.0;
        } else {
            return sum;
        }
    }
};