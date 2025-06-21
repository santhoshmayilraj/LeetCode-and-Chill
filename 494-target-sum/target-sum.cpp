class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        helper(count,nums,target,0,0);
        return count;
    }

    void helper(int &count,vector<int> &nums,int target,int curr,int sum)
    {
        if(curr == nums.size() and sum == target)
        {
            count++;
            return;
        }

        if(curr >= nums.size()) 
        {
            return;
        }

        helper(count,nums,target,curr+1,sum+nums[curr]);
        helper(count,nums,target,curr+1,sum-nums[curr]);
        return;
    }
};