class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefsum(nums.size()+1,0);
        for(vector<int> i:queries)
        {
            prefsum[i[0]]++;
            prefsum[i[1]+1]--;
        }
        int prev = 0;
        for(int i=0;i<nums.size();i++)
        {
            prev += prefsum[i];
            nums[i] = nums[i] - prev;
            if(nums[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};