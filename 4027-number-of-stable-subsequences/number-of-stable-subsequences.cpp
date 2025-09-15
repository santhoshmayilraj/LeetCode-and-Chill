class Solution {
public:
    int mod = 1e9+7;
    int helper(vector<int>& nums,int parity,int ind,int count,vector<vector<vector<int>>>& dp)
    {
        if(ind >= nums.size())
        {
            return (parity == -1 ? 0 : 1);
        }
        if(parity != -1 && dp[ind][parity][count] != -1)
        {
            return dp[ind][parity][count];
        }
        int not_take = helper(nums,parity,ind+1,count,dp);
        int take = 0;
        if(parity == -1)
        {
            take = helper(nums,nums[ind]%2,ind+1,1,dp);
        }
        else
        {
            if(nums[ind]%2 == parity)
            {
                if(count < 2)
                {
                    take = helper(nums,parity,ind+1,count+1,dp);
                }
            }
            else
            {
                take = helper(nums,nums[ind]%2,ind+1,1,dp);
            }
        }
        int ans = (take + not_take) % mod;
        if(parity != -1) dp[ind][parity][count] = ans;
        return ans;
    }
    int countStableSubsequences(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(nums,-1,0,0,dp);
    }
};
