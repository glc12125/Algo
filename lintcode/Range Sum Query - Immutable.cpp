class NumArray {
private:
    vector<int> m_prefixSum;
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        m_prefixSum.resize(len + 1);
        m_prefixSum[0] = 0;
        for(int i = 1; i <= len; ++i) {
            m_prefixSum[i] = m_prefixSum[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return m_prefixSum[j+1] - m_prefixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */