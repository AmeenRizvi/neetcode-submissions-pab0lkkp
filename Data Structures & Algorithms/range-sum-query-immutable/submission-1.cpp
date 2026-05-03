class NumArray {
    vector<int>prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        int runningSum = 0;

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            prefixSum[i] = runningSum;
        }
    }
    
    int sumRange(int left, int right) {
        int rightSum = prefixSum[right];
        int leftSum = left == 0 ? 0 : prefixSum[left-1];

        return rightSum - leftSum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */