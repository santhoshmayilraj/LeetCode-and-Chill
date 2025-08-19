class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        ans = helper(0,INT_MIN,0,nums,dp);
        return ans;
    }

    int helper(int curr,int prev,int ind,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(curr >= nums.size())
        {
            return 0;
        }
        if(dp[curr][ind] != -1)
        {
            return dp[curr][ind];
        }
        int temp = 0;

        if(prev < nums[curr])
        {
            temp = 1+helper(curr+1,nums[curr],curr+1,nums,dp);
        }
        temp = max(temp,helper(curr+1,prev,ind,nums,dp));
        dp[curr][ind] = temp;
        return temp;
    }
};