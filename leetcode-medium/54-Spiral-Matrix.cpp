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