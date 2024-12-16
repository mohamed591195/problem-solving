// class Solution {
// public:
//     int dfsHelper(string& s, int l, int r, vector<vector<int>>& memo) {
//         if (l<0 || r >= s.size()) return 0;
//         if (memo[l][r] != -1) return memo[l][r];
//         if (l == r) return memo[l][r] = 1 + dfsHelper(s, l-1, r+1, memo);
//         if (s[l] == s[r]) return memo[l][r] = 2 + dfsHelper(s, l-1, r+1, memo);
        
//         return memo[l][r] = max(
//             dfsHelper(s, l-1, r, memo),
//             dfsHelper(s, l, r+1, memo)
//         );
//     }
//     int longestPalindromeSubseq(string s) {
//         int maxLen = 0;
//         vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
//         for (int i=0; i<s.size(); ++i) {
//             maxLen = max(maxLen, dfsHelper(s, i, i, memo));
//             maxLen = max(maxLen, dfsHelper(s, i, i+1, memo));
//         }
//         return maxLen;
//     }
// };

// iterative dp solution 
// the trick here is that longest palindromic subsequence is the longest common subsequence between the string
// and its reverse 

class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<int> curr(text1.size()+1, 0);
        vector<int> prev(text1.size()+1, 0);
        
        for (int i=1; i<=text2.size(); ++i) {
            char& ch1 = text2[i-1];
            for (int j=1; j<=text1.size(); ++j){
                char& ch2 = text1[j-1];
                if (ch1 == ch2) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return curr[text1.size()];
    }
    int longestPalindromeSubseq(string s) {
        string original = s;
        reverse(s.begin(), s.end());
        return longestCommonSubsequence(original, s);
    }
};