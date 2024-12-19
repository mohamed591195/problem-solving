class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int L=0;
        int result = 0;
        // double currSum = 0;
        int currSum = 0;

        int R = 0;
        while ((R - L) < (k -1)) {
            currSum += arr[R];
            R++;
        }

        for (R; R<arr.size(); ++R){
            currSum += arr[R];
            // if (currSum/(double)k >= threshold) result++;
            if (currSum/k >= threshold) result++;
            currSum -= arr[L];
            L++;
        }
        return result;
    }
};