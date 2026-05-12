class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> result(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++)
        {
            int x = n-1-i;
            int y = m-1;
            for(int j=m-1;j>=0;j--)
            {
                if(boxGrid[i][j] =='.')
                {
                    continue;
                }
                else if(boxGrid[i][j] == '#')
                {
                    result[y][x] = '#';
                    y--;
                }
                else
                {
                    result[j][x] = '*';
                    y = j-1;
                }
            }
        }
        return result;
    }
};