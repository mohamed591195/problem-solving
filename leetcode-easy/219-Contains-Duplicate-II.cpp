// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int L = 0;
//         unordered_set<int> window;
        
//         for (int R=0; R<nums.size(); ++R){
//             if (R - L > k) {
//                 window.erase(nums[L]);
//                 L++;
//             }
//             if (window.count(nums[R])) return true;
//             window.insert(nums[R]);
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int L = 0, R = 0;
        unordered_set<int> items;
        while (R - L <= k && R < nums.size()) {
            if (items.count(nums[R])) return true;
            items.insert(nums[R++]);
        }

        for (R; R<nums.size(); ++R) {
            items.erase(nums[L++]);
            if (items.count(nums[R])) return true;
            items.insert(nums[R]);
        }
        return false;
    }
};

