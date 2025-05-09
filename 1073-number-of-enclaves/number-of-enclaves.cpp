class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int row_sz = grid.size();
        int col_sz = grid[0].size();
        int count(0);
        for(int i=0;i<row_sz;i++)
        {
            if(!visited[i][0] and grid[i][0] == 1)
            {
                helper(grid,visited,i,0);
            }
            if(!visited[i][col_sz-1] and grid[i][col_sz-1] == 1)
            {
                helper(grid,visited,i,col_sz-1);
            }
        }  
        for(int i=0;i<col_sz;i++)
        {
            if(!visited[0][i] and grid[0][i] == 1)
            {
                helper(grid,visited,0,i);
            }
            if(!visited[row_sz-1][i] and grid[row_sz-1][i]==1)
            {
                helper(grid,visited,row_sz-1,i);
            }
        }  
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j] and !visited[i][j])
                {
                    count++;
                }
            }
        }   
        return count;
    }

    void helper(vector<vector<int>> &board,vector<vector<int>> &visited,int i,int j)
    {
        visited[i][j] = 1;
        if(i-1 >= 0 and !visited[i-1][j] and board[i-1][j] == 1)
        {
            helper(board,visited,i-1,j);
        }
        if(j-1 >= 0 and !visited[i][j-1] and board[i][j-1] == 1)
        {
            helper(board,visited,i,j-1);
        }
        if(i+1 < board.size() and !visited[i+1][j] and board[i+1][j] == 1)
        {
            helper(board,visited,i+1,j);
        }
        if(j+1 < board[0].size() and !visited[i][j+1] and board[i][j+1] == 1)
        {
            helper(board,visited,i,j+1);
        }
        return;
    }
};