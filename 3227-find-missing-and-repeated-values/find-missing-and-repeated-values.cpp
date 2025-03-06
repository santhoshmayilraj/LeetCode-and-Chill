class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> hash;
        int a,b;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                hash[grid[i][j]]++;
            }
        }  
        for(int i=0;i<grid.size()*grid.size();i++)
        {
            if(hash[i+1]==0)
            {
                a = i+1;
            }
            if(hash[i+1] == 2)
            {
                b = i+1;
            }
        }  
        vector<int> ans = {b,a};
        return ans;    
    }
};