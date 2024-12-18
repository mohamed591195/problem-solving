class Solution {
public:
// cacluating the min subarray sum, and the rest (which is on the sides ) become the max 
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0, currMin = 0;
        int maxSum = nums[0], minSum = nums[0];
        int arraySum = 0;

        for (const int& num: nums){
            arraySum += num;

            currMax += num;
            maxSum = max(currMax, maxSum);
            currMax = max(currMax, 0); // zero if negative 

            currMin += num;
            minSum = min(currMin, minSum);
            currMin = min(currMin, 0); // zero if positive, for the next iteration
        }

        if (maxSum < 0) { // all elements are negative
            return maxSum;
        }
        return max(maxSum, arraySum-minSum);
    }
};