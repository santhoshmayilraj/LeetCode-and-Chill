class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans(0);
        for(int i=0;i<grid.size();i++)
        {
            int l(0),r(grid[0].size()-1);
            int temp (grid[0].size());
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(grid[i][mid] < 0)
                {
                    temp = mid;
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            ans += grid[0].size() - temp;
        }
        return ans;        
    }
};