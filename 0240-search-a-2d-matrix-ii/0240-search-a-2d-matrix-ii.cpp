class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1; // total number of rows
        int col = 0;
        int t_col = matrix[0].size() - 1; //total number of column
        while(row >= 0 and col <= t_col ){
            int guess = matrix[row][col];
            if(guess == target){
                return true;
            }
            if(guess > target){
                row = row - 1;
            }
            if(guess < target){
                col = col + 1;
            }
        }
        return false;
    }
};