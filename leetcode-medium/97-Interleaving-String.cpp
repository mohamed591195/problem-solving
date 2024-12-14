// class Solution {
// public:
//     bool dfsHelper(string& s1, string& s2, string& s3, int p1, int p2, int p3, 
//                                                     vector<vector<vector<int>>>& memo) {
        
//         if (memo[p1][p2][p3] != -1) return memo[p1][p2][p3];

//         if (p3 == s3.size()){
//             return memo[p1][p2][p3] = (p2 == s2.size() && p1 == s1.size());
//         }

//         if (p1 < s1.size() && s1[p1] == s3[p3] && dfsHelper(s1, s2, s3, p1+1, p2, p3+1, memo)){
//             return memo[p1][p2][p3] = true;
//         }

//         if (p2 < s2.size() && s2[p2] == s3[p3] && dfsHelper(s1, s2, s3, p1, p2+1, p3+1, memo)) {
//             return memo[p1][p2][p3] = true;
//         }

//         return memo[p1][p2][p3] = false;
//     }

//     bool isInterleave(string s1, string s2, string s3) {
//         if (s1.size() + s2.size() != s3.size()) return false;
//         vector<vector<vector<int>>> memo(
//             s1.size()+1, 
//             vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1))
//         );
//         return dfsHelper(s1, s2, s3, 0, 0, 0, memo);
//     }
// };

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {

//         if (s1.size() + s2.size() != s3.size()) return false;
//         vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
//         dp[0][0]= true;

        
//         // fill the first row
//         for (int i=1; i<=s2.size(); ++i) {
//             dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
//         }
        

//         // fill the first column 
//         for (int i=1; i<=s1.size(); ++i) {
//             dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
//         }
        
        
//         for (int i=1; i<=s1.size(); ++i) {
//             for (int j=1; j<=s2.size(); ++j) {
//                 dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || 
//                             (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
//             }
//         }
       
//         return dp[s1.size()][s2.size()];
//     }
// };

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<bool> dp(s2.size()+1, false);
        dp[0] = true;

        for (int i=1; i<=s2.size(); ++i) {
            dp[i] = (dp[i-1] && s2[i-1] == s3[i-1]);
        }

        for (int i=1; i<=s1.size(); ++i) {
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for (int j=1; j<=s2.size(); ++j) {
                dp[j] = dp[j-1] && s2[j-1] == s3[j+i-1] || dp[j] && s1[i-1] == s3[j+i-1];
            }
        }
        return dp[s2.size()];
    }
};