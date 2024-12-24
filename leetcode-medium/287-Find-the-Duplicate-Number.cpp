class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        int slow2 = nums[0];
        
        while(slow2 != slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};