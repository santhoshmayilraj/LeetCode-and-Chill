class Solution { // this is brute fore backtracking 
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        int count = helper(text1,text2,text1.size()-1,text2.size()-1,dp);
        return count;        
    }

    int helper(string &text1,string &text2,int sz_1,int sz_2,vector<vector<int>> &dp)
    {
        if(sz_1 < 0 or sz_2 < 0)
        {
            return 0;
        }
        if(dp[sz_1][sz_2] != -1)
        {
            return dp[sz_1][sz_2];            
        }
        int temp = 0;
        if(text1[sz_1] == text2[sz_2])
        {
            dp[sz_1][sz_2] = 1+helper(text1,text2,sz_1-1,sz_2-1,dp);
            return dp[sz_1][sz_2];
        }
        else
        {
            temp = max(temp,helper(text1,text2,sz_1-1,sz_2,dp));
            temp = max(temp,helper(text1,text2,sz_1,sz_2-1,dp));
        }
        dp[sz_1][sz_2] = temp;
        return temp;
    }
};