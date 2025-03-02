class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums1.size();i++)
        {
            hash[nums1[i][0]] = nums1[i][1];
        }
        for(int i=0;i<nums2.size();i++)
        {
            hash[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> ans;
        for(auto i:hash)
        {
            vector<int> temp = {i.first,i.second};
            ans.push_back(temp);
        }        
        sort(ans.begin(),ans.end());
        return ans;
    }
};