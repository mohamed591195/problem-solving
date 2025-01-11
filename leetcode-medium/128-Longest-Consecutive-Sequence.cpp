class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int counter = 1;
        int maxStreak = 0;
        for(int i = 1; i<nums.size(); ++i){
            if (nums[i] == nums[i-1]) continue; 
            else if (nums[i] - nums[i-1] == 1) counter++;
            else {
                maxStreak = max(maxStreak, counter);
                counter = 1;
            }
        } 
        return max(maxStreak, counter);     
    }
};