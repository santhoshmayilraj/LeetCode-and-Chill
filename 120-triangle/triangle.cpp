class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> temp = triangle;
        for (int i = 0; i < temp.size(); ++i) {
            for (int j = 0; j < temp[i].size(); ++j) {
                temp[i][j] = INT_MAX;
            }
        }

        int min_value = INT_MAX;
        int last_row = temp.size() - 1;
        for (int j = 0; j < temp[last_row].size(); ++j) {
            min_value = min(min_value, helper(triangle, temp, last_row, j));
        }
        return min_value;
    }

private:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& temp, int curr_x, int curr_y) {
        // Boundary check
        if (curr_x < 0 || curr_y < 0 || curr_y >= triangle[curr_x].size()) {
            return INT_MAX;
        }

        // Base case: top of the triangle
        if (curr_x == 0 && curr_y == 0) {
            return triangle[0][0];
        }

        // Return already computed value
        if (temp[curr_x][curr_y] != INT_MAX) {
            return temp[curr_x][curr_y];
        }

        // Recursively compute the minimum path sum to current cell
        int from_left = helper(triangle, temp, curr_x - 1, curr_y - 1);
        int from_above = helper(triangle, temp, curr_x - 1, curr_y);

        int min_prev = min(from_left, from_above);
        if (min_prev == INT_MAX) {
            return INT_MAX;
        }

        temp[curr_x][curr_y] = min_prev + triangle[curr_x][curr_y];
        return temp[curr_x][curr_y];
    }
};
