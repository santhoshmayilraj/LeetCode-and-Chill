class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        for(int i:coins)
        {
            if(i<amount)
            {
                dp[i] = 1;
            }
        }
        int ans = helper(coins,amount,dp);
        if(ans == INT_MAX)
        {
            return -1;
        }      
        return ans;
    }

    int helper(vector<int> &coins,int rem,vector<int> &dp)
    {
        if(rem == 0)
        {
            return 0;
        }
        if(rem < 0)
        {
            return INT_MAX;
        }
        if(dp[rem] != -1)
        {
            return dp[rem];
        }
        int temp = INT_MAX;
        for(int i:coins)
        {
            if(rem-i >= 0)
            {
                temp = min(temp,helper(coins,rem-i,dp));
            }
        }
        if(temp != INT_MAX)
        {
            temp += 1;
        }
        dp[rem] = temp;
        return dp[rem];
    }
};