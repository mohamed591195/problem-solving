class Solution {
public:
    int maxSubArray(vector<int>& nums) { //kadane's algorithm
        int currSum = 0;
        int maxSum = nums[0];

        for (const int& num: nums) {
            currSum += num;
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0); // if it's negative we get rid of it 
        }
        return maxSum;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) { //kadane's algorithm
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            if (currSum > 0) currSum += nums[i];
            else currSum = nums[i];
            maxSum = max(maxSum, currSum); 
        }
        return maxSum;
    }
};