class NumMatrix {
    vector<vector<int>> pSumMat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int r=1; r<rows; ++r){
            matrix[r][0] += matrix[r-1][0];
        }
        for (int c=1; c<cols; ++c){
            matrix[0][c] += matrix[0][c-1];
        }

        for (int r=1; r<rows; ++r){
            for (int c=1; c<cols; ++c){
                matrix[r][c] += matrix[r-1][c] + matrix[r][c-1] - matrix[r-1][c-1];
            }
        }

        pSumMat = move(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        if (row1 > 0 && col1 > 0){
            return pSumMat[row2][col2] - pSumMat[row2][col1-1] - pSumMat[row1-1][col2] + pSumMat[row1-1][col1-1];
        }
        else if (col1 > 0) {
            return pSumMat[row2][col2] - pSumMat[row2][col1-1];
        }
        else if (row1 > 0) {
            return pSumMat[row2][col2] - pSumMat[row1-1][col2];
        }
        return pSumMat[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */