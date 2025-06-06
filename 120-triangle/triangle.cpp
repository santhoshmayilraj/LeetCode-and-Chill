class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = triangle[0][0];
        for(int i=0;i<dp.size()-1;i++)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]+triangle[i+1][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+triangle[i+1][j+1]);
            }
        }
        int min_ans = INT_MAX;
        for(int i=0;i<dp[dp.size()-1].size();i++)
        {
            min_ans = min(min_ans,dp[dp.size()-1][i]);
        }
        return min_ans;
    }
};