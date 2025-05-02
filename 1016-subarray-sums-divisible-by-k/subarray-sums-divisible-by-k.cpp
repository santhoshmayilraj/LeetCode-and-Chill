class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0] = 1;
        int sum = 0,count(0);
        for(int i:nums)
        {
            sum+= i;
            count += hash[(sum%k+k)%k];
            hash[(sum%k+k)%k]++;
        }
        return count;
    }
};