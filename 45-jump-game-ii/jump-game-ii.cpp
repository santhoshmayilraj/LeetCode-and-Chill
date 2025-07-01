class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 0;
        }
        int jump_count(1),curr_end(nums[0]),far_jump(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(curr_end >= nums.size()-1)
            {
                break;
            }
            if(i > curr_end)
            {
                curr_end = far_jump;
                jump_count++;
            }
            far_jump = max(i+nums[i],far_jump);
        }
        return jump_count;
    }
};