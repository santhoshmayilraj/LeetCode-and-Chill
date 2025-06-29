class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int l(0),r(0);
        int count_even(0);
        int count_odd(0);
        while(r<nums.size())
        {
            if(nums[r]%2 != 0)
            {
                count_odd++;
            }
            if(l<r and count_odd > k)
            {
                if(nums[l]%2 !=0)
                {
                    count_odd--;
                }
                l++;
                count_even = 0;
            }
            if(count_odd == k)
            {
                while(l<r and nums[l]%2 == 0)
                {
                    count_even++;
                    l++;
                }
                count += count_even;
                count++;
            }
            r++;
        }
        return count;        
    }
};