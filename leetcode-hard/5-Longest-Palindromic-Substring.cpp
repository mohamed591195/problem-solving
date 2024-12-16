class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string substring;

        for (int i=0; i<s.size(); ++i) {
            int l=i, r=i;
        
            while(l>= 0 && r<= s.size() && s[l] == s[r]) {
                if ((r-l+1) > maxLen) {
                    maxLen = r-l+1;
                    substring = s.substr(l, maxLen);
                }
                l--; r++;
            }
            l = i, r = i+1;
            while (l>=0 && r<=s.size() && s[l] == s[r]) {
                if ((r-l+1) > maxLen) {
                    maxLen = r-l+1;
                    substring = s.substr(l, maxLen);
                }
                l--; r++;
            }
        }
        return substring;
    }
};