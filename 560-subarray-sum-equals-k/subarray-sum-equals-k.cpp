class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i:nums)
        {
            sum+= i;
            ans += hash[sum-k];
            hash[sum]++;
        }
        return ans;
    }
};