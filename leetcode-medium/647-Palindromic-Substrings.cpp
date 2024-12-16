class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;

        for (int i=0; i<s.size(); ++i) {
            int l=i, r=i;
        
            while(l>= 0 && r<= s.size() && s[l] == s[r]) {
                counter++;
                l--; r++;
            }
            l = i, r = i+1;
            while (l>=0 && r<=s.size() && s[l] == s[r]) {
                counter ++;
                l--; r++;
            }
        }
        return counter;
    }
};