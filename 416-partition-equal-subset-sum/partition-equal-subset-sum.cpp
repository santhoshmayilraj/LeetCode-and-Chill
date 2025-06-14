class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)
        {
            sum += i;
        }
        if(sum %2 != 0)
        {
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return helper(dp,nums,sum/2,0,0) == 1;
    }

    int helper(vector<vector<int>> &dp,vector<int> &nums,int sum,int curr_index,int curr_sum )
    {
        if(curr_sum == sum)
        {
            return 1;
        }
        if(curr_index == nums.size() or curr_sum > sum)
        {
            return 0;
        }
        if(dp[curr_index][curr_sum] != -1)
        {
            return dp[curr_index][curr_sum];
        }
        int temp = 0;
        for(int i=curr_index;i<nums.size();i++)
        {
            if(nums[i] > sum)
            {
                continue;
            }
            temp = helper(dp,nums,sum,i+1,curr_sum+nums[i]);
            if(temp == 1)
            {
                break;
            }
        }
        dp[curr_index][curr_sum] = temp;
        return dp[curr_index][curr_sum];
    }
};