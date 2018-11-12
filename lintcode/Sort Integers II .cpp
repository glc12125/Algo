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

    void mergeSort(std::vector<int>& nums, std::vector<int>& temp, int start, int end) {
        if(start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid + 1, end);
        int i = start;
        int tempIndex = start;
        int j = mid + 1;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp[tempIndex++] = nums[i++];
            } else {
                temp[tempIndex++] = nums[j++];
            }
        }

        while(i <= mid) {
            temp[tempIndex++] = nums[i++];
        }

        while(j <= end) {
            temp[tempIndex++] = nums[j++];
        }

        for(int i = start; i <= end; ++i) {
            nums[i] = temp[i];
        }
    }

    void heapSort(vector<int>& nums) {
        // build max heap: for each root node bottom to top and right to left
        for (int i = nums.size() / 2; i >= 0; i--) {
            maxHeapify(nums, i, nums.size() - 1);
        }

        // swap first and adjust the new root to right position
        for (int i = nums.size() - 1; i > 0; i--) {
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            // after each iteration, largest goes to ith, next end at i - 1
            maxHeapify(nums, 0, i - 1);
        }
    }

    void maxHeapify(vector<int>&  nums, int start, int end) {
        int parent = start;

        // top to bottom
        while (parent <= end) {
            int left = parent * 2 + 1;
            int right = parent * 2 + 2;
            int child = -1;

            if (left <= end && right <= end) {
                // large value as swap candidate
                child = (nums[left] >= nums[right] ? left : right);
            } else if (left <= end) {
                child = left;
            } else {
                return;
            }

            // max heap root >= left && root >= right
            if (nums[parent] >= nums[child]) {
                return;
            }

            // swap
            int tmp = nums[parent];
            nums[parent] = nums[child];
            nums[child] = tmp;

            // update parent index
            parent = child;
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
        //qSort(A, 0, size - 1);
        //heapSort(A);
        std::vector<int> temp(size);
        mergeSort(A, temp, 0, size - 1);
    }
};