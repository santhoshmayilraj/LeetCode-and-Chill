class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }   

        int r(0),l(0);

        while(l<nums.size() or r<nums.size())
        {
            if(nums[l]==0)
            {
                while(r<nums.size() and nums[r]==0)
                {
                    r++;
                }
                if(r<nums.size())
                {
                    swap(nums[l],nums[r]);
                }
            }
            l++;
            r++;
        }  
        return nums;
    }
};