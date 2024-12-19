// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> window;
//         int maxLen = 0;
//         int L = 0;

//         for (int R=0; R<s.size(); ++R){
//             while (window.count(s[R])){
//                 window.erase(s[L]);
//                 L++;
//             }
//             window.insert(s[R]);
//             maxLen = max(maxLen, R-L+1); 
//         }

//         return maxLen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> items;
        int maxLen = 0;

        for(int L=0, R=0; R<s.size(); ++R){
            while (items.count(s[R])){
                items.erase(s[L++]);
            }
            items.insert(s[R]);
            maxLen = max(maxLen, R-L+1);
        }
        return maxLen;
    }
};