class Solution {
public:
    int lengthOfLastWord(string s) {
        // all edge cases ("", " ", "a") are covered 
        int i=s.size()-1;
        while(i >=0 && s[i] == ' ') --i;
        int j = i;
        while(j >=0 && s[j] != ' ') --j;
        return i-j;
    }
};
