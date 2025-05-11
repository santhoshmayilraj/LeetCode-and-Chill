class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count(0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,count);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid,int i,int j,int &count)
    {
        grid[i][j] = -1;
        if(i-1 >=0  and grid[i-1][j] == 1)
        {
            dfs(grid,i-1,j,count);
        }
        else
        {
            if(i-1 < 0 or grid[i-1][j] == 0)
            {
                count++;
            }
        }

        if(j-1 >=0 and grid[i][j-1] == 1)
        {
            dfs(grid,i,j-1,count);
        }
        else
        {
            if(j-1 < 0  or grid[i][j-1] == 0)
            {
                count++;
            }
        }

        if(i+1 < grid.size() and grid[i+1][j] == 1)
        {
            dfs(grid,i+1,j,count);
        }
        else
        {
            if(i+1 >= grid.size() or grid[i+1][j] == 0)
            {
                count++;
            }
        }

        if(j+1 < grid[0].size() and grid[i][j+1] == 1)
        {
            dfs(grid,i,j+1,count);
        }
        else
        {
            if(j+1 >= grid[0].size() or grid[i][j+1] == 0)
            {
                count++;
            }
        }
        return;
    }
};