class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        dp[0][0][0] = 0;
        for(int i=1;i<=sz;i++)
        {
            int count_z = 0;
            int count_o = 0;
            for(int j=0;j<strs[i-1].size();j++)
            {
                if(strs[i-1][j] == '0')
                {
                    count_z++;
                }
                else
                {
                    count_o++;
                }
            }
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j-count_z >= 0 and k-count_o >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-count_z][k-count_o]+1);
                    }
                }
            }
        }
        int ans = -1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                ans = max(ans,dp[sz][i][j]);
            }
        }
        return ans;
    }
};