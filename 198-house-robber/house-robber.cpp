class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        helper(dp,nums,nums.size()); 
        return dp[nums.size()-1];       
    }
    int helper(vector<int> &dp,vector<int> &nums,int n)
    {
        if(n==1)
        {
            dp[0] = nums[0];
            return nums[0];
        }
        if(n==2)
        {
            dp[1] = max(nums[0],nums[1]);
            return max(nums[0],nums[1]);
        }
        if(dp[n-1] != -1)
        {
            return dp[n-1];
        }
        dp[n-1] = max(helper(dp,nums,n-1),helper(dp,nums,n-2)+nums[n-1]);
        return dp[n-1];
    }
};