// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         if (nums.size() == 1) return 0; 
//         vector<int> postfix = nums;

//         for (int i = 1; i<nums.size(); ++i) {
//             nums[i] += nums[i-1];
//         }
//         for (int i = nums.size()-2; i >= 0; --i){
//             postfix[i] += postfix[i+1];

//         }

//         for (int i=0; i<nums.size(); ++i) {
//             if (i && i<nums.size()-1) {
//                 if (nums[i-1] == postfix[i+1]) return i;
//                 continue;
//             }
//             else if (i && nums[i-1] == 0) return i;
//             else if (i<nums.size()-1 && postfix[i+1] == 0) return i;
//         }
//         return -1;
//     }
// };

// another nicer solution 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i=0; i<nums.size(); ++i) {
            rightSum -= nums[i];
            if (rightSum == leftSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
