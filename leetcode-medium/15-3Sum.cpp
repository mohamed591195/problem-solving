class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-2; ++i) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            int L = i+1, R = nums.size() - 1;

            while (L < R) {
                int total = nums[i] + nums[L] + nums[R];
                if (total < 0) L++;
                else if (total > 0) R--;
                else {
                    result.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L+1]) L++;
                    while (L < R && nums[R] == nums[R-1]) R--;
                    L++;
                    R--;
                }
            }
        }
        return result;
    }
}; 