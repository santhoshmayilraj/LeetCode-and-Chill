class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n,string(n,'.'));
        helper(ans,nQueens,n,0);
        return ans;
    }

    void helper(vector<vector<string>> &ans,vector<string> &nQueens,int n,int curr_row)
    {
        if(curr_row == n)
        {
            ans.push_back(nQueens);
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(nQueens,i,curr_row,n))
            {
                nQueens[curr_row][i] = 'Q';
                helper(ans,nQueens,n,curr_row+1);
                nQueens[curr_row][i] = '.';
            }
        }
        return;
    }

    bool issafe(vector<string> &nQueens,int col,int row,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(nQueens[i][col] == 'Q')
            {
                return false;
            }
        }

        for(int new_row = row-1,new_col = col-1;new_row >=0 and new_col >= 0 ; new_row--,new_col--)
        {
            if(nQueens[new_row][new_col] == 'Q')
            {
                return false;
            }
        }

        for(int new_row = row-1,new_col = col+1;new_row >=0 and new_col < n;new_row--,new_col++)
        {
            if(nQueens[new_row][new_col] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};