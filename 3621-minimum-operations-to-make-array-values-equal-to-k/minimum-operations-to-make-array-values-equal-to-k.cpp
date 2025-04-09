class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i:nums)
            {
                if(i>k)
                {
                    hash[i]++;
                }
                else if(i<k)
                {
                    return -1;
                }     
            }
        return hash.size();
        
    }
};