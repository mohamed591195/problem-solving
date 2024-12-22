// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size(), INT_MAX);
//         dp[0] = 0;
//         for (int i=0; i<nums.size(); ++i) {
//             for(int j=i+1; j <= i+nums[i] && j<nums.size(); j++) {
//                 dp[j] = min(dp[j], 1+dp[i]);
//             }
//         }
//         return dp[nums.size() - 1];
//     }
// };


// a nicer solution 
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, furthest = 0;

        for (int i=0; i<nums.size()-1; ++i) {
            furthest = max(furthest, i+nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = furthest;
            }
        }
        return jumps;
    }
};