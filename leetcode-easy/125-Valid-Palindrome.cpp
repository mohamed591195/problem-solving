class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size() - 1;
        while (L <= R) {
            while (L < R && !isalnum(s[L])) L++;
            while (R > L && !isalnum(s[R])) R--;
            if (tolower(s[L++]) != tolower(s[R--])) return false;
        }
        return true;
    }
};