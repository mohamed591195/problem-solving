class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<vector<unordered_set<int>>> subBoxes(3, vector<unordered_set<int>>(3));
        //flattening the 2D matrix, we can access the sets using index equation below
        // vector<unordered_set<int>> subBoxes(9);

        for(int r=0; r<board.size(); ++r){
            for(int c=0; c<board[0].size(); ++c){
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '0';
                if (rows[r].count(val)) return false;
                if (cols[c].count(val)) return false;
                if (subBoxes[r/3][c/3].count(val)) return false;
                // int idx = 3*(r/3) + c/3;
                // if (subBoxes[idx].count(val)) return false;
                rows[r].insert(val);
                cols[c].insert(val);
                // subBoxes[idx].insert(val);
                subBoxes[r/3][c/3].insert(val);
            }
        }
        return true;
    }
};