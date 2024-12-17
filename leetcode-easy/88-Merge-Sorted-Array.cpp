class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = n - 1;
        int j = m - 1;
        int k = m + n - 1;
        
        while (i >= 0) {
            if (j >=0 && nums2[i] < nums1[j]){
                nums1[k--] = nums1[j--];
            } else {
                nums1[k--] = nums2[i--];
            }
        }
    }
};