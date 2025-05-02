class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0] = 1; 
        int sum(0);
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(hash[sum%k]!=0 and hash[sum%k]!=i+1)
            {
                return true;
            }
            if(hash[sum%k]==0)
            {
                hash[sum%k] = i+2;
            }
            hash[sum%k] = min(hash[sum%k],i+2);
        }
        return false;
    }
};