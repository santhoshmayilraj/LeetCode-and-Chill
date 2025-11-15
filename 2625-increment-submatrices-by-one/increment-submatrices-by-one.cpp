class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n+1,vector<int>(n+1,0));
        for(vector<int> i : queries)
        {
            int in_x = i[0];
            int in_y = i[1];
            int en_x = i[2];
            int en_y = i[3];

            ans[in_x][in_y] += 1;
            ans[in_x][en_y+1] += -1;
            ans[en_x+1][in_y] += -1;
            ans[en_x+1][en_y+1] += 1;
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                ans[i][j] = ans[i][j] + ans[i][j-1];
            }
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                ans[i][j] = ans[i-1][j] + ans[i][j];
            }
        }
        vector<vector<int>> final_mat(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                final_mat[i][j] = ans[i][j];
            }
        }
        return final_mat;
    }
};