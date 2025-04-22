class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]] = i;
        }
        for(int j=0;j<operations.size();j++)
        {
            if(hash[operations[j][0]]!=-1)
            {
                nums[hash[operations[j][0]]] = operations[j][1];
                hash[operations[j][1]] = hash[operations[j][0]];
                hash[operations[j][0]] = -1;
            }
        }
        hash.clear();
        return nums;        
    }
};