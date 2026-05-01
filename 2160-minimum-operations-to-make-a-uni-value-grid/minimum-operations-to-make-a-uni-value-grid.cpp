class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int curr_elem = temp[temp.size()/2];
        int rem = curr_elem % x;
        int ans = 0;
        for(int i:temp)
        {
            if(i%x != rem)
            {
                return -1;
            }
            ans += (abs(curr_elem - i)/x);
        }
        return ans;
    }
};