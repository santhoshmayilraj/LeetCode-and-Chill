class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<3;k++)
                {
                    if(j==1)
                    {
                        dp[i][j][k] = max((-prices[i] + dp[i+1][0][k]),dp[i+1][1][k]);
                    }
                    else
                    {
                        dp[i][j][k] = max((prices[i]+dp[i+1][1][k-1]),dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];        
    }

    int helper(int curr,vector<int> &prices,int buy,int trans,vector<vector<vector<int>>> &dp)
    {
        if(curr >= prices.size() or trans == 0)
        {
            return 0;
        }
        if(dp[curr][buy][trans] != -1)
        {
            return dp[curr][buy][trans];
        }
        int temp;
        if(buy)
        {
            temp = max(-prices[curr] + helper(curr+1,prices,0,trans,dp),helper(curr+1,prices,1,trans,dp));
        }
        else
        {
            temp = max(prices[curr] + helper(curr+1,prices,1,trans-1,dp),helper(curr+1,prices,0,trans,dp));
        }
        dp[curr][buy][trans] = temp;
        return temp;
    }
};