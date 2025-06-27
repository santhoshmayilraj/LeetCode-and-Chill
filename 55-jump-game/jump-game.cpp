class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag;
        vector<int> dp(nums.size(),-1);
        flag = helper(nums,0,dp);
        return flag;        
    }

    bool helper(vector<int> &nums,int curr,vector<int> &dp)
    {
        if(curr == nums.size()-1)
        {
            return true;
        }
        if(dp[curr] != -1)
        {
            if(dp[curr] == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool temp = false;
        for(int i=0;i<nums[curr];i++)
        {
            if(curr+i+1 < nums.size())
            {
                temp = temp or helper(nums,curr+i+1,dp);
            }
            else
            {
                break;
            }
        }
        if(temp == true)
        {
            dp[curr] = 1;
        }
        else
        {
            dp[curr] = 0;
        }
        return temp;
    }
};