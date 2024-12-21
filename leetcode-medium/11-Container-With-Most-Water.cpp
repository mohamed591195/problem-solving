class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int maxArea = 0;
        while (L <= R) {
            if (height[L] < height[R]) {
                maxArea = max(maxArea, (R-L) * height[L++]);
            }
            else {
                maxArea = max(maxArea, (R-L) * height[R--]);
            }
        }
        return maxArea; 
    }
};