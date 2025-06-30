class Solution { // greedy approach 
public:
    bool canJump(vector<int>& nums) {
        int max_jump = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i<= max_jump)
            {
                max_jump = max(max_jump,i+nums[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};