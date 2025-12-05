class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total_sum = 0;
        for(int i:nums)
        {
            total_sum += i;
        }
        int count(0),running_sum(0);
        for(int i=0;i<nums.size()-1;i++)
        {
            running_sum += nums[i];
            total_sum -= nums[i];
            if((total_sum-running_sum)%2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};