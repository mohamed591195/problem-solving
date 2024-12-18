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

// another way of writing the solution using kadanes algorithm
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMin = nums[0], currMax = nums[0];
        int minSum = nums[0], maxSum = nums[0];
        int totalSum = nums[0];

        for(int i=1; i<nums.size(); ++i) {
            if (currMax > 0) currMax += nums[i];
            else currMax = nums[i];
            maxSum = max(currMax, maxSum);

            if (currMin < 0) currMin += nums[i];
            else currMin = nums[i];
            minSum = min(currMin, minSum); 

            totalSum += nums[i]; 
        }
        
        if (maxSum < 0) return maxSum;
        if (totalSum - minSum > maxSum) return totalSum - minSum;
        return maxSum;
    }
};
