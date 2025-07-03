class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        int ans = helper(s,rev,0,0,dp);
        return ans;
    }

    int helper(string &s,string &rev,int curr_1,int curr_2,vector<vector<int>> &dp)
    {
        if(curr_1 >= s.size() or curr_2 >= rev.size())
        {
            return 0;
        }
        if(dp[curr_1][curr_2] != -1)
        {
            return dp[curr_1][curr_2];
        }
        if(s[curr_1]  == rev[curr_2])
        {
            dp[curr_1][curr_2] = 1+helper(s,rev,curr_1+1,curr_2+1,dp);
            return dp[curr_1][curr_2];
        }
        int temp = 0;
        temp = max(temp,helper(s,rev,curr_1+1,curr_2,dp));
        temp = max(temp,helper(s,rev,curr_1,curr_2+1,dp));
        dp[curr_1][curr_2] = temp;
        return temp;
    }
};  