class Solution {
private:
    int partition(vector<int> & nums, int start, int end) {
        if(start == end) return start;
        int i = start;
        int j = end;
        int pivot = nums[(start + end) / 2];
        while(i <= j) {
            while(i <= j && nums[i] < pivot) {
                ++i;
            }
            while(i <= j && nums[j] > pivot) {
                --j;
            }
            if(i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
                --j;
            }
        }
        return i;
    }

    void qSort(vector<int> & nums, int start, int end) {
        if(start < end) {
            int pivotIndex = partition(nums, start, end);
            qSort(nums, start, pivotIndex - 1);
            qSort(nums, pivotIndex, end);
        }
    }
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        int size = A.size();
        if(size == 0) return;
        qSort(A, 0, size - 1);
    }
};