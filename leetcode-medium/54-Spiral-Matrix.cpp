class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left=0, right=matrix[0].size(); //rows
        int up=0, down=matrix.size(); //cols

        int j = 0, k = 0;

        int counter = right*down;

        while(counter > 0){
            while(j < right && counter){
                result.push_back(matrix[k][j++]);
                counter--;
            }
            j--;
            right--;
            k++;
            while(k < down && counter){
                result.push_back(matrix[k++][j]);
                counter--;
            }
            k--;
            down--;
            j--;
            while(j >= left && counter){
                result.push_back(matrix[k][j--]);
                counter--;
            }
            j++;
            left++;
            k--;
            while(k > up && counter){
                result.push_back(matrix[k--][j]);
                counter--;
            }
            up++;
            j = left;
            k=up;
        }
        return result;
    }
};


// An Enhaned version 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Traverse from Left to Right
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // Traverse from Top to Bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse from Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
