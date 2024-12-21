// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int L = 0;
//         int R = 1;
//         for (R; R < nums.size(); ++R){
//             if (L == 0 || nums[R] == nums[L] && nums[L] != nums[L-1] || nums[R] != nums[L]) {
//                 L++;
//                 nums[L] = nums[R];
//             }
//         }
//         return L+1;
//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (const int& n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};
