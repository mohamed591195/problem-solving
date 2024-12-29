// class Solution {
// public:
//     string reverseWords(string s) {
//         int i = 0;
//         stack<string> words;
//         while (i < s.size() && !isalnum(s[i])) i++;
//         while(i<s.size()){
//             string word = \\;
//             while (i < s.size() && isalnum(s[i])){
//                 word += s[i];
//                 i++;
//             }
//             words.push(word);
//             while (i < s.size() && !isalnum(s[i])) i++;
//         }
//         s = \\;
//         while(!words.empty()) {
//             s += (words.top()) + \ \;
//             words.pop();
//         }
//         s.pop_back();
//         return s;
//     }
// };

// the idea is to reverse the whole string then reverse each word
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int L = 0, R = 0;
        
        while (R < s.size()) {
            while (L < s.size() && !isalnum(s[L])) L++; 
            R = L;
            while (R < s.size() && isalnum(s[R])) R++;
            reverse(s.begin()+L, s.begin()+R);
            L = R;
        }
        // removing extra spaces
        L = R = 0;
        
        while (R < s.size()) {
            while (R < s.size() && !isalnum(s[R])) R++; // skipping leading white spaces
            while (R < s.size() && isalnum(s[R])) s[L++] = s[R++];
            s[L++] = ' '; // adding one space
        }
        // Remove any trailing space
        while (L > 0 && s[L - 1] == ' ') L--; 
        s.erase(L);
        return s;
    }
};