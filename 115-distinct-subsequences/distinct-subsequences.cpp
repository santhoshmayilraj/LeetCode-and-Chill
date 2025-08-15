class Solution {
public:
    int numDistinct(string s, string t) {
        int count = 0;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        count = helper(s,t,0,0,dp);
        return count;
    }

    int helper(string &s,string &t,int l,int r,vector<vector<int>> &dp)
    {
        if(r >= t.size())
        {
            return 1;
        }
        if(l >= s.size())
        {
            return 0;
        }

        if(dp[l][r] != -1)
        {
            return dp[l][r];
        }
        int curr = 0;

        if(s[l] == t[r])
        {
            curr += helper(s,t,l+1,r+1,dp);
        }
        curr += helper(s,t,l+1,r,dp);
        dp[l][r] = curr;
        return curr;
    }
};