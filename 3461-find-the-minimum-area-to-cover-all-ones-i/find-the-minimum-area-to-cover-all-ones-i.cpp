class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int x_low = grid.size(),x_high = 0;
        int y_low = grid[0].size(),y_high = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    x_low = min(x_low,i);
                    x_high = max(x_high,i);
                    y_low = min(y_low,j);
                    y_high = max(y_high,j);
                }
            } 
        }
        return (x_high - x_low + 1)*(y_high-y_low+1);
    }
};