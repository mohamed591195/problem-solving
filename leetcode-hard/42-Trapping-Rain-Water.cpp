class Solution {
public:
    int trap(vector<int>& height) {
        int L=0, R = height.size()-1;
        int maxL = height[L], maxR = height[R];
        int water = 0;
        while(L < R) {
            if (maxL < maxR) {
                if (maxL > height[++L]) water += maxL - height[L];
                else maxL = height[L];
            }
            else {
                if (maxR > height[--R]) water += maxR - height[R];
                else maxR = height[R];
            }
        }
        return water;
    }
};