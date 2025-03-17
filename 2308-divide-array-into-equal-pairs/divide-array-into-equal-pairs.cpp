class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> hash;
        int count(0);
        for(int i:nums)
        {
            hash[i]++;
            if(hash[i]%2 == 0)
            {
                count++;
            }
        }

        return nums.size()/2 == count;
              
    }
};