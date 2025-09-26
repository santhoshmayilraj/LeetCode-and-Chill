class Solution {
public:
    int helper(vector<int>& nums,int l,int r,int x)
    {
        while(r >= l)
        {
            int mid = (l+r)/2;
            if(nums[mid] >= x)
            {
                r = mid-1;
            }
            else 
            {
                l = mid+1;
            }
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if(nums.size() < 3)
        {
            return count;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1 and nums[i] != 0;j++)
            {
                int ans = helper(nums,i+2,nums.size()-1,nums[i]+nums[j]);
                count += ans - j - 1;
            }
        }
        return count;
    }
};