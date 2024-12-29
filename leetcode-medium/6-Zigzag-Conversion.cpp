
// matrix for display (side work, not the problem solution) 
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (s.size() <= 1 || numRows == 1) return s;
//         int singleCols = numRows - 2;
//         int combinedBillars = numRows + singleCols;
//         int cols = (s.size() / combinedBillars);
//         cols = cols * (singleCols + 1) + ceil((s.size() % combinedBillars) / static_cast<double>(numRows));
//         vector<vector<char>> mat(numRows, vector<char>(cols, ' '));

//         int sIdx = 0;
//         for (int c=0; c<cols; ++c){
//             if (sIdx >= s.size()) break;
//             int remainder = c % (singleCols + 1); 
//             if (remainder == 0) {
//                 for (int r=0; r<numRows; ++r) {
//                     mat[r][c] = s[sIdx++];
//                 }
//             }
//             else {
//                 mat[numRows-remainder-1][c] = s[sIdx++];
//             }
//         }
//         sIdx = s.size();
//         s = \\;
//         for (int r=0; r<numRows; ++r) {
//             for(int c=0; c<cols; ++c) {
//                 if (mat[r][c] != ' '){
//                     s += mat[r][c];
//                     if (--sIdx == 0) return s;
//                 }
//             }
//         }
//         return s;
//     }
// };


class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 1 || numRows == 1) return s;
        int jumps = 2 * numRows - 2;
        string out;
        for (int i=0; i<numRows; ++i) {
            int j = i;
             
            while(j< s.size()){
                out += s[j];
                if (i % (numRows - 1) && (j + 2 + 2*(numRows-1-(i+1))) < s.size()) out += s[j + 2 + 2*(numRows-1-(i+1))];
                j += jumps;  
            }
        }
        return out;
    }
};