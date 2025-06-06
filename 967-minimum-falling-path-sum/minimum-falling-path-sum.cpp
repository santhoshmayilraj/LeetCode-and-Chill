class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        for(int i=0;i<matrix[0].size();i++)
        {
            dp[0][i] = matrix[0][i];
        }
        vector<int> dy = {1,0,-1};
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                for(int k:dy)
                {
                    int new_y = j + k;
                    if(new_y < 0 or new_y >= matrix[0].size())
                    {
                        continue;
                    }
                    dp[i+1][new_y] = min(dp[i+1][new_y],dp[i][j]+matrix[i+1][new_y]);
                }                
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {
            ans = min(ans,dp[matrix.size()-1][i]);
        }
        return ans;
    }
};