class Solution {
public:
    int helper(string &s,int start,int end,vector<vector<int>>& dp)
    {
        if(start >= end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int curr = INT_MAX;
        if(s[start] == s[end])
        {
            curr = min(curr,helper(s,start+1,end-1,dp));            
        }
        else
        {
            curr = min(curr,helper(s,start+1,end,dp)+1);
            curr = min(curr,helper(s,start,end-1,dp)+1);
        }
        dp[start][end] = curr;
        return curr;
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1,dp);
    }
};