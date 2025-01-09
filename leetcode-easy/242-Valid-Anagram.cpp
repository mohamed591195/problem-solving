// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unordered_map<char, int> m;
//         int counter = s.size();
//         for(char& ch: s){
//             m[ch]++;
//         }

//         for(char& ch: t){
//             m[ch]--;
//             if(m[ch] < 0) return false;
//             counter--;
//         }
//         if (counter == 0) return true;
//         return false;
//     }
// };
// another syntax 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq_array(26, 0);

        for (const char& ch: s){
            freq_array[ch-97]++;
        }
        for (const char& ch: t){
            freq_array[ch-97]--;
        }
        for (const int& num: freq_array) {
            if (num) return false;
        }
        return true;
    }
};