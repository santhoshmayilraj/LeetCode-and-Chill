class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefsum(nums.size()+1,0);
        for(vector<int> i:queries)
        {
            prefsum[i[0]]++;
            prefsum[i[1]+1]--;
        }
        for(int i=1;i<prefsum.size();i++)
        {
            prefsum[i] = prefsum[i] + prefsum[i-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i] - prefsum[i];
            if(nums[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};