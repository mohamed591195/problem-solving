// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0, j=0;
//         for (int i=0; i<nums.size(); ++i) {
//             while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
//             nums[j++] = nums[i];
//         }
//         return j;
//     }
// };

// 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int& num: nums){
            if (i == 0 || num > nums[i-1]) nums[i++] = num;
        }
        return i;
    }
};