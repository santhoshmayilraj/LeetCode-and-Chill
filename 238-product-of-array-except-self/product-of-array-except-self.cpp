class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int zero_count = 0;
        int zero_idx = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero_count++;
                zero_idx = i;
            }
            else
            {
                temp *= nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(zero_count == 0)
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i] = temp/nums[i];
            }
        }
        else if(zero_count ==1)
        {
            ans[zero_idx] = temp;
        }
        return ans;
    }
};