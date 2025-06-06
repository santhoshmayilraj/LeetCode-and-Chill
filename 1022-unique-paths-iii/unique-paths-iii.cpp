class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> start = {-1,-1};
        pair<int,int> end = {-1,-1};
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        int ans(0);
        int count(0);
        int total = grid.size() * grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    start.first = i;
                    start.second = j;
                }
                else if(grid[i][j] == 2)
                {
                    end.first = i;
                    end.second = j;
                }
                else if(grid[i][j] == -1)
                {
                    total--;
                }
            }
        }
        helper(visited,grid,dx,dy,ans,start.first,start.second,end.first,end.second,count,total); 
        return ans;      
    }

    void helper(vector<vector<int>> &visited,vector<vector<int>> &grid,vector<int> &dx,vector<int> &dy, int &ans,int curr_x,int curr_y,int end_x,int end_y,int count,int total)
    {
        if(visited[curr_x][curr_y])
        {
            return;
        }
        if(curr_x == end_x and curr_y == end_y and count == total-1)
        {
            ans++;
            return;
        }
        visited[curr_x][curr_y]  = 1;
        count++;
        for(int i=0;i<4;i++)
        {
            int new_x = curr_x + dx[i];
            int new_y = curr_y + dy[i];
            if(new_x < 0 or new_y < 0 or new_x >= grid.size() or new_y >= grid[0].size() or visited[new_x][new_y] or grid[new_x][new_y] == -1)
            {
                continue;
            }
            helper(visited,grid,dx,dy,ans,new_x,new_y,end_x,end_y,count,total);
        }
        visited[curr_x][curr_y] = 0;
        return;
    }
};