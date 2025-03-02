class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int first = nums[0];
        int last = nums[nums.size()-1];
        if(k==1 or k > nums.size())
        {
            unordered_map<int,int> hash;
            for(int i:nums)
                {
                    hash[i]++;
                }
            int ans = -1;
            for(auto i:hash)
                {
                    if(i.second == 1)
                    {
                        ans = max(ans,i.first);
                    }
                }
            return ans;
        }
        if(k==nums.size())
        {
            int ans = -1;
            for(int i:nums)
                {
                    ans = max(ans,i);
                }
            return ans;
        }
        if(first == last)
        {
            return -1;
        }
        for(int i=1;i<nums.size()-1;i++)
            {
                if(nums[i] == first)
                {
                    first = -1;
                }
                if(nums[i] == last)
                {
                    last = -1;
                }
            }
        return max(first,last);        
    }
};