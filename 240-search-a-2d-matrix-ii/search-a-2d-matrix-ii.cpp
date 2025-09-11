class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int curr_x = 0;
        int curr_y = matrix[0].size()-1;
        while(curr_x < matrix.size() and curr_y >= 0)
        {
            if(matrix[curr_x][curr_y] == target)
            {
                return true;
            }
            else if(matrix[curr_x][curr_y] > target)
            {
                curr_y--;
            }
            else
            {
                curr_x++;
            }
        }
        return false;
    }
};