class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L=0;
        int R = numbers.size() - 1;
        int sum;
        while (L <= R) {
            sum = numbers[L] + numbers[R];
            if (sum == target) return {L+1, R+1};
            else if (sum > target) R--;
            else L++; 
        }
        return vector<int>{};
    }
};