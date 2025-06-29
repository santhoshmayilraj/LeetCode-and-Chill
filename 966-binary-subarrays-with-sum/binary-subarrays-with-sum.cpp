class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int l(0),r(0);
        int curr_sum(0);
        int count_zero(0);
        while(r<nums.size())
        {
            curr_sum += nums[r];
            if(l<r and curr_sum > goal)
            {
                curr_sum -= nums[l];
                l++;   
                count_zero = 0;
            }
            if(curr_sum == goal)
            {
                while(l<r and nums[l] == 0)
                {
                    count_zero++;
                    l++;
                }
                ans += count_zero;
                ans++;
            }
            r++;
        }
        return ans;        
    }
};