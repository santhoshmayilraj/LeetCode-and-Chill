class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                // cout << i << j << dp[i][j] << "\n";
            }
        }
        int ans = word1.size() + word2.size() - (2*dp[dp.size()-1][dp[0].size()-1]);
        return ans;
    }
};