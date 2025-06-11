class Solution { // min-max algorithm
public:
    bool stoneGame(vector<int>& piles) {
        bool flag = true;
        int curr_left = 0;
        int curr_right = piles.size()-1;
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int alice_score = helper(flag,curr_left,curr_right,piles,0,dp);
        if(alice_score > 0)
        {
            return true;
        }
        return false;
    }

    int helper(bool flag,int curr_left,int curr_right,vector<int> &piles,int curr_score,vector<vector<int>> &dp)
    {
        if(curr_left == curr_right)
        {
            return piles[curr_left];
        }
        if(dp[curr_left][curr_right] != -1)
        {
            return dp[curr_left][curr_right];
        }
        if(flag)
        {
            dp[curr_left][curr_right] = max(helper(!flag,curr_left+1,curr_right,piles,curr_score+piles[curr_left],dp),helper(!flag,curr_left,curr_right-1,piles,curr_score+piles[curr_right],dp));
            return dp[curr_left][curr_right];
        }
        else
        {
            dp[curr_left][curr_right] = min(helper(!flag,curr_left+1,curr_right,piles,curr_score-piles[curr_left],dp),helper(!flag,curr_left,curr_right-1,piles,curr_score-piles[curr_right],dp));
            return dp[curr_left][curr_right];
        }
        
    }
};