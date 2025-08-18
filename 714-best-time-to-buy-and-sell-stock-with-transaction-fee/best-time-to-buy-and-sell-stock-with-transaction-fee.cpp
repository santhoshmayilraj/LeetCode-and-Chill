class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        int ans = helper(0,prices,fee,1,dp);
        return ans;
    }

    int helper(int curr,vector<int> &prices,int &fee,int buy,vector<vector<int>> &dp)
    {
        if(curr >= prices.size())
        {
            return 0;
        }

        if(dp[curr][buy] != -1)
        {
            return dp[curr][buy];
        }

        int temp;
        if(buy)
        {
            temp = max(-prices[curr]+helper(curr+1,prices,fee,0,dp),helper(curr+1,prices,fee,1,dp));
        }
        else
        {
            temp = max(prices[curr]+ helper(curr+1,prices,fee,1,dp)-fee,helper(curr+1,prices,fee,0,dp));
        }
        dp[curr][buy] = temp;
        return temp;
    }
}; 