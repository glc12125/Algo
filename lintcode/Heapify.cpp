// Time O(nlogn)
class Solution {
private:
    void siftUp(vector<int> &A, int index) {
        while(index != 0) {
            int parentIndex = (index - 1) / 2;
            if(A[parentIndex] > A[index]) {
                std::swap(A[index], A[parentIndex]);
            } else {break;}
            index = parentIndex;
        }
    }
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        int len = A.size();

        for(int i = 0; i < len; ++i) {
            siftUp(A, i);
        }
    }
};

// Time O(n)
class Solution {
private:
    void siftDown(vector<int> &A, int index) {
        int len = A.size();
        while(index < len) {
            int minIndex = index;
            int leftSonIndex = 2 * index + 1;
            if(leftSonIndex < len && A[minIndex] > A[leftSonIndex]) {
                minIndex = leftSonIndex;
            }
            int rightSonIndex = 2 * index + 2;
            if(rightSonIndex < len && A[minIndex] > A[rightSonIndex]) {
                minIndex = rightSonIndex;
            }
            if(minIndex == index) break;

            std::swap(A[index], A[minIndex]);
            index = minIndex;
        }
    }
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        int len = A.size();

        for(int i =  len / 2; i > -1; --i) {
            siftDown(A, i);
        }
    }
};