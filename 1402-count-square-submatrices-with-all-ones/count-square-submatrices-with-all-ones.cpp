class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));

        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]}) + 1;
                    ans+= dp[i][j];
                }
            }
        }

        // for(int i=0;i<matrix.size();i++)
        // {
        //     for(int j=0;j<matrix[0].size();j++)
        //     {
        //         if(matrix[i][j] == 1)
        //         {
        //             ans += helper(i,j,matrix,dp);
        //         }
        //     }
        // }
        return ans;
    }

    int helper(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        int temp = 1;
        int curr = 0;
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if(x+1 < matrix.size() and matrix[x+1][y] == 1)
        {
            curr = helper(x+1,y,matrix,dp);
        }
        if(y+1 < matrix[0].size() and matrix[x][y+1] == 1)
        {
            curr = min(curr,helper(x,y+1,matrix,dp));
        }
        else
        {
            curr = 0;
        }
        if(x+1 < matrix.size() and y+1 < matrix[0].size() and matrix[x+1][y+1] == 1)
        {
            curr = min(curr,helper(x+1,y+1,matrix,dp));
        }
        else
        {
            curr = 0;
        }
        dp[x][y] = temp+curr;
        return temp+curr;
    }
};