// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char, int> lettermap;
//         lettermap.emplace('I', 1);
//         lettermap.emplace('V', 5);
//         lettermap.emplace('X', 10);
//         lettermap.emplace('L', 50);
//         lettermap.emplace('C', 100);
//         lettermap.emplace('D', 500);
//         lettermap.emplace('M', 1000);

//         int result = 0;

//         for (int i=0; i < s.size(); ++i){
//             if (i+1 < s.size()) {
//                 if (s[i] == 'I') {
//                     i += 1;
//                     if (s[i] == 'V') result += 4;
//                     else if (s[i] == 'X') result += 9;
//                     else {
//                         result += 1;
//                         i -= 1;
//                     }
//                 }
//                 else if (s[i] == 'X') {
//                     i += 1;
//                     if (s[i] == 'L') result += 40;
//                     else if (s[i] == 'C') result += 90;
//                     else {
//                         result += 10;
//                         i -= 1;
//                     }
//                 }
//                 else if (s[i] == 'C') {
//                     i += 1;
//                     if (s[i] == 'D') result += 400;
//                     else if (s[i] == 'M') result += 900;
//                     else {
//                         result += 100;
//                         i -= 1;
//                     }
//                 }
//                 else result += lettermap[s[i]];
//             }
//             else  result += lettermap[s[i]];
//         }
//         return result;
//     }
// };

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m.emplace('I', 1);
        m.emplace('V', 5);
        m.emplace('X', 10);
        m.emplace('L', 50);
        m.emplace('C', 100);
        m.emplace('D', 500);
        m.emplace('M', 1000);
        
        int result = 0;

        for (int i=0; i < s.size(); ++i){
            if (i+1 < s.size() && m[s[i]] < m[s[i+1]]) {
                result -= m[s[i]];
            }
            else result += m[s[i]];
        }
        return result;
    }
};