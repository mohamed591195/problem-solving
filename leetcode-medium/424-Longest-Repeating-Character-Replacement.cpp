// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int L=0;
//         int maxf = 0;
//         int maxWindow = 0;
//         unordered_map<char, int> freqs;

//         for (int R=0; R<s.size(); ++R) {
//             maxf = max(maxf, ++freqs[s[R]]);

//             while((R - L + 1) - maxf > k ){
//                 freqs[s[L]]--;
//                 L++;
//             }

//             maxWindow = max(maxWindow, (R - L + 1));
//         }

//         return maxWindow;
//     }
// };


class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0, maxWindow = 0;
        unordered_map<char, int> freq;

        for (int L=0, R=0; R<s.size(); ++R) {
            maxf = max(maxf, ++freq[s[R]]);

            while(R-L+1 - maxf > k){
                --freq[s[L++]];
            }
            maxWindow = max(maxWindow, R-L+1);
        }
        return maxWindow;
    }
};
