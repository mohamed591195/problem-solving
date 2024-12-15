// class Solution {
// public:
//     string dfsHelper(string& str1, string& str2, int p1, int p2, vector<vector<string>>& memo) {
//         if (p1 == str1.size()) return str2.substr(p2);
//         if (p2 == str2.size()) return str1.substr(p1);

//         if (!memo[p1][p2].empty()) return memo[p1][p2];

//         if (str1[p1] == str2[p2]) 
//             return memo[p1][p2] = str1[p1] + dfsHelper(str1, str2, p1+1, p2+1, memo);

//         string left = str1[p1] + dfsHelper(str1, str2, p1+1, p2, memo);
//         string right = str2[p2] + dfsHelper(str1, str2, p1, p2+1, memo);

//         return memo[p1][p2] = (left.size() >= right.size())? right: left;
//     }

//     string shortestCommonSupersequence(string str1, string str2) {
//         vector<vector<string>> memo(str1.size(), vector<string>(str2.size(), ""));
//         return dfsHelper(str1, str2, 0, 0, memo);
//     }
// };

// recusive solution exceeded the memory limit, maybe an iterative solution with space optimization works
// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         vector<string> curr(str2.size()+1, "");
//         vector<string> prev(str2.size()+1, "");

//         for (int i=0; i<str2.size(); ++i){
//             prev[i+1] = prev[i] + str2[i];
//         }

//         for (char& ch1: str1){
//             curr[0] = curr[0] + ch1;

//             for (int i=1; i<=str2.size(); ++i) {
//                 char ch2 = str2[i-1];
//                 if (ch1 == ch2) curr[i] = prev[i-1] + ch1;
//                 else {
//                     string left = prev[i] + ch1;
//                     string right = curr[i-1] + ch2;
//                     curr[i] = (left.size() <= right.size())? left : right;
//                 }
//                 cout << curr[i] << " ";
//             }
//             prev = curr;
//             cout << endl;
//         }
//         return curr[str2.size()];
//     }
// };

// using another approach to avoid memory limit
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i=1; i<=n1; ++i) {
            dp[i][0] = i;
        }
        for (int i=1; i<=n2; ++i) {
            dp[0][i] = i;
        }
        // Step 1: Compute SCS length using DP
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) { 
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Reconstruct the SCS
        string result;
        int i = n1, j = n2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                --i; --j;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                result += str1[i - 1];
                --i;
            } else {
                result += str2[j - 1];
                --j;
            }
        }

        // Append remaining characters from either string
        while (i > 0) {
            result += str1[i - 1];
            --i;
        }
        while (j > 0) {
            result += str2[j - 1];
            --j;
        }

        // Reverse the result since we built it backwards
        reverse(result.begin(), result.end());
        return result;
    }
};