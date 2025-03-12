class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count_neg(0),count_pos(nums.size());
        int l(0),r(nums.size()-1);
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]<0)
            {
                count_neg = mid+1;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        l = 0;
        r = nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]<=0)
            {
                l = mid+1;
            }
            else
            {
                count_pos = mid;
                r = mid-1;
            }
        }
        count_pos = nums.size() - count_pos;
        return max(count_neg,count_pos);
    }
};