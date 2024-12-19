// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int i=0;
//         string LCP;
//         while(true){
//             if (i >= strs[0].size()) return LCP;
//             char ch = strs[0][i];
//             for(int j=1; j<strs.size(); ++j){
//                 if (i >= strs[j].size() || ch != strs[j][i]) return LCP;
//             }
//             LCP += ch;
//             i++;
//         }
//         return LCP;
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string LCP;
        while(i < strs[0].size()){
            char ch = strs[0][i];
            for(int j=1; j<strs.size(); ++j){
                if (i >= strs[j].size() || ch != strs[j][i]) return LCP;
            }
            LCP += ch;
            i++;
        }
        return LCP;
    }
};