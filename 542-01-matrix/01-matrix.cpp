class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>> BFS;
        int count = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 0)
                {
                    BFS.push({i,j});
                }
            }
        }
        while(!BFS.empty())
        {
            int sz = BFS.size();
            for(int k=0;k<sz;k++)
            {
                pair<int,int> curr = BFS.front();
                BFS.pop();
                int i = curr.first;
                int j = curr.second;
                if(ans[i][j] == -1)
                {
                    ans[i][j] = count;
                }
                if(i-1 >= 0 and ans[i-1][j] == -1)
                {
                    BFS.push({i-1,j});
                }
                if(j-1 >=0 and ans[i][j-1] == -1)
                {
                    BFS.push({i,j-1});
                } 
                if(i+1 < mat.size() and ans[i+1][j] == -1)
                {
                    BFS.push({i+1,j});
                }
                if(j+1 < mat[0].size() and ans[i][j+1] == -1)
                {
                    BFS.push({i,j+1});
                }
            } 
            count++;
        }
        return ans;                
    }
};