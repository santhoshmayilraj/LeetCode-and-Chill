class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n);
        if(n==1)
        {
            return false;
        }
        dp[0] = false;
        dp[1] = true;
        return helper(n,dp);
    }

    bool helper(int n,vector<bool> &dp)
    {
        if(dp[n-1] != NULL)
        {
            return dp[n-1];
        }

        for(int i=1;i*i<=n;i++)
        {
            if(n%i == 0 and !helper(n-i,dp))
            {
                dp[n-1] = true;
                return true;
            }
        }
        dp[n-1] = false;
        return false;
    }
};