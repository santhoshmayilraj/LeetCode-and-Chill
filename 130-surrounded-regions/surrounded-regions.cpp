class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board[0].size();i++)
        {
            if(!visited[0][i] and board[0][i] == 'O')
            {
                helper(board,visited,0,i);
            }
            if(!visited[board.size()-1][i] and board[board.size()-1][i] == 'O')
            {
                helper(board,visited,board.size()-1,i);
            }
            
        }        
        for(int i=1;i<board.size()-1;i++)
        {
            if(!visited[i][0] and board[i][0] == 'O')
            {
                helper(board,visited,i,0);
            }
            if(!visited[i][board[0].size()-1] and board[i][board[0].size()-1] == 'O')
            {
                helper(board,visited,i,board[0].size()-1);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(visited[i][j])
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void helper(vector<vector<char>> &board,vector<vector<int>> &visited,int i,int j)
    {
        visited[i][j] = 1;
        if(i-1 >= 0 and !visited[i-1][j] and board[i-1][j] == 'O')
        {
            helper(board,visited,i-1,j);
        }
        if(j-1 >= 0 and !visited[i][j-1] and board[i][j-1] == 'O')
        {
            helper(board,visited,i,j-1);
        }
        if(i+1 < board.size() and !visited[i+1][j] and board[i+1][j] == 'O')
        {
            helper(board,visited,i+1,j);
        }
        if(j+1 < board[0].size() and !visited[i][j+1] and board[i][j+1] == 'O')
        {
            helper(board,visited,i,j+1);
        }
        return;
    }
};