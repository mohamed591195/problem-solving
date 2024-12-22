// we are making our checks on two things 
// 1 if the current prefix-sum equal the target, it mean (sum from 1st element to current element = k)
// 2 if there's a range sum == k (which we do normally using prefix sum by subtracting two prefix sum)
// for that we need to keep track of all previous (prefix sums) with their counts, because having negative
// numbers mean we can have a prefix-sum value appear more than once
class Solution {  
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        int counter = 0;
        unordered_map<int, int> prefixRecord; 
        
        prefixSum[0] = nums[0]; 
        for (int i=1; i<nums.size(); ++i) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        for (int i=0; i<nums.size(); ++i) {
            if (prefixSum[i] == k) counter++;
            if (prefixRecord.count(prefixSum[i] - k)) {
                counter += prefixRecord[prefixSum[i] - k];
            }

            prefixRecord[prefixSum[i]]++;
        }
        return counter;
    }
};