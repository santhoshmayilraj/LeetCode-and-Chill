class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count(0);
        unordered_map<int,int> hash;
        int j(0);
        for(int i:nums)
            {
                if(hash[i] <= 0)
                {
                    hash[i]++;
                }
                else
                {
                    while(hash[i]>0 and j<nums.size())
                        {
                            count++;
                            hash[nums[j]]--;
                            j++;
                        if(j<nums.size())
                            {
                                hash[nums[j]]--;
                                j++;
                            }
                        if(j<nums.size())
                            {
                                hash[nums[j]]--;
                                j++;
                            }
                        }
                    hash[i]++;
                }
            }
            return count;
    }
};