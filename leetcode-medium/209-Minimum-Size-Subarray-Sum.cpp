// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int currSum = 0;
//         int minWindowLen = INT_MAX;
//         int L = 0;

//         for (int R=0; R<nums.size(); ++R) {
//             currSum += nums[R];
//             while(currSum >= target){
//                 minWindowLen = min(minWindowLen, R-L+1);
//                 currSum -= nums[L];
//                 L++;
//             }
//         }
//         if (minWindowLen == INT_MAX) return 0;
//         return minWindowLen; 
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX, currSum = 0;

        int L=0;
        for (int R=0; R<nums.size(); ++R) {
            currSum += nums[R];

            while (currSum >= target) {
                minLen = min(minLen, R-L+1);
                currSum -= nums[L++];
            }
        }
        return (minLen == INT_MAX)? 0: minLen;
    }
};