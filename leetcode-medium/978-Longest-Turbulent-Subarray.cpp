// class Solution {
// public:
//     int maxTurbulenceSize(vector<int>& arr) {
//         int currEvenLen = 1, maxEvenLen = 1, currOddLen = 1, maxOddLen = 1;

//         for (int i=1; i<arr.size(); ++i) {
            
//             if ((i & 1) && arr[i] > arr[i-1] || (!(i&1)) && arr[i] < arr[i-1]) {
//                 currOddLen++;
//                 maxOddLen = max(maxOddLen, currOddLen);
//                 currEvenLen = 1;
//             }
//             else if ((i & 1) && arr[i] < arr[i-1] || (!(i&1)) && arr[i] > arr[i-1]) {
//                 currEvenLen++;
//                 maxEvenLen = max(maxEvenLen, currEvenLen);
//                 currOddLen = 1;
//             }
//             else { // equal case
//                 currEvenLen = 1;
//                 currOddLen = 1;
//             }
            
//         }
//         return max(maxEvenLen, maxOddLen);
//     }
// };

// another way of writing the syntax
// class Solution {
// public:
//     int maxTurbulenceSize(vector<int>& arr) {
//         int maxEven = 0, maxOdd = 0;
//         int currEven = 0, currOdd = 0;

//         for (int k=0; k<arr.size()-1; ++k) {
//             if ((k & 1) && arr[k] > arr[k+1] || !(k & 1) && arr[k] < arr[k+1]) {
//                 currEven = 0;
//                 currOdd++;
//                 maxOdd = max(currOdd, maxOdd);
//             }
//             else if ((k & 1) && arr[k] < arr[k+1] || !(k & 1) && arr[k] > arr[k+1]) {
//                 currOdd = 0;
//                 currEven++;
//                 maxEven = max(currEven, maxEven);
//             }
//             else { //equal case
//                 currEven = 0;
//                 currOdd = 0;
//             }
//         }

//         return 1 + max(maxEven, maxOdd);
//     }
// };

//another solution
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int dec = 1, inc = 1;
        int maxLen = 1;
        // we try to find the regular pattern with the max len, this means if it's increasing this step
        // the following step should be decreasing, this why we reverse turns each iteration
        // if we are in the same pattern, we should enter (if clause) in one turn and the next turn we enter
        // (else if clause) and so on
        // if a pattern is broken we enter the same (clause) twice, this is why we reset the dec and inc
        // variables in each clause 
        for (int k=1; k<arr.size(); ++k) {
            if (arr[k] > arr[k-1]){
                inc = dec + 1;
                dec = 1;
            }
            else if (arr[k] < arr[k-1]) {
                dec = inc + 1;
                inc = 1;
            }
            else {
                dec = inc = 1;
            }
            maxLen = max(maxLen, max(dec, inc));
        }
        
        return maxLen;
    }
};
