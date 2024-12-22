class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> postfix(n);
        postfix[n-1] = nums[n-1];

        while (--n){ // decrement done before evaluation, so n=1 is the last n value to enter the loop, not n=0 
            postfix[n-1] = nums[n-1] + postfix[n]; 
        }
        if (postfix[1] == 0) return 0;//first edge case

        n = nums.size();
        // overwrite nums to be prefix
        for (int i=1; i<n; ++i){
            if (i < n-1 && nums[i-1] == postfix[i+1]) return i;
            nums[i] += nums[i-1];
        }
        if (nums[n-2] == 0) return n-1; //second edge case
        
        return -1;
    }
};