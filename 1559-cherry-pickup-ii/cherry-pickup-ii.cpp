class Solution { // bottom-up approach
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        for(int i=0;i<grid[0].size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==j)
                {
                    dp[grid.size()-1][i][j] = grid[grid.size()-1][j];
                }
                else
                {
                    dp[grid.size()-1][i][j] = grid[grid.size()-1][i]+grid[grid.size()-1][j];
                }
            }
        }   
        vector<int> directions = {-1,0,1};
        for(int i=grid.size()-2;i>=0;i--)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                for(int k=0;k<grid[0].size();k++)
                {
                    if(j==k)
                    {
                        dp[i][j][k] = grid[i][j];
                    }
                    else
                    {
                        dp[i][j][k] = grid[i][j] + grid[i][k];
                    }
                    int temp = INT_MIN;
                    for(int j1:directions)
                    {
                        for(int k1:directions)
                        {
                            int new_j = j+j1;
                            int new_k = k+k1;
                            if(new_j <0 or new_k <0 or new_j >= grid[0].size() or new_k >= grid[0].size())
                            {
                                continue;
                            }
                            temp = max(temp,dp[i+1][new_j][new_k]);
                        }
                    } 
                    dp[i][j][k] += temp;
                }
            }
        }    
         return dp[0][0][grid[0].size()-1];
    }
};