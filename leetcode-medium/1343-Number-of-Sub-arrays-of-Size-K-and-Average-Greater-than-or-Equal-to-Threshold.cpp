// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         int L=0;
//         int result = 0;
//         // double currSum = 0;
//         int currSum = 0;

//         int R = 0;
//         while ((R - L) < (k -1)) {
//             currSum += arr[R];
//             R++;
//         }

//         for (R; R<arr.size(); ++R){
//             currSum += arr[R];
//             // if (currSum/(double)k >= threshold) result++;
//             if (currSum/k >= threshold) result++;
//             currSum -= arr[L];
//             L++;
//         }
//         return result;
//     }
// };

// if the problem isn't about subarrays (for example subsequence, or subsets) we would use a recursive solution
// to get all the possible combinations that satisfy the condition 
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currWindowSum = 0;
        int L = 0, R=0;
        int counter = 0;
        while(R-L < k && R<arr.size()) {
            currWindowSum += arr[R++];
        }
        if (currWindowSum / k >= threshold) counter++;

        for (R; R<arr.size(); ++R){
            currWindowSum -= arr[L++];
            currWindowSum += arr[R];
            if (currWindowSum / k >= threshold) counter++;
        }
        return counter;
    }
};
