class NumArray {
    vector<int> prefSum;
public:
    NumArray(vector<int>& nums) {
        for(int i=1; i<nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        prefSum = move(nums);
    }
    
    int sumRange(int left, int right) {
        if (left) return prefSum[right] - prefSum[left-1];
        return prefSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */