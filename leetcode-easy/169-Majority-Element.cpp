// naive solution 
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> cache;
//         int majority = nums.size() / 2;
//         for (int num: nums) {
//             cache[num]++;
//         }
//         for (auto& [key, val]: cache) {
//             if (val > majority) return key;
//         }
//         return 0;
//     }
// };

// O(1) memory solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0; int curr = nums[0];

        for (int& num: nums) {
            if (counter == 0) {
                curr = num;
            }
            if (curr == num) {
                counter++;
            }
            else {
                counter--;
            }
        }
        return curr;
    }
};