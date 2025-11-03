class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l(0),r(0);
        int len = -1;
        int count = k;

        while(r<nums.size())
        {
            if(nums[r] == 0 and count == 0)
            {
                if(nums[l]==0)
                {
                    count++;
                }
                l++;
            }
            else
            {
                if(nums[r]==1)
                {
                    r++;
                }
                else
                {
                    r++;
                    count--;
                }
            }
            if(r-l>len)
            {
                len = r-l;
            }            
        }
        return len;                                                                                                                                                                                                                                                                                                                                
        
    }
};