class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        ans = helper(0,prices,1,2,dp);
        return ans;
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