class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        bool flag = true;
        vector<vector<int>> edges(n);
        for(int i=0;i<dislikes.size();i++)
        {
            edges[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            edges[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        vector<int> visited(n,0);
        unordered_map<int,int> group;
        for(int i=0;i<edges.size();i++)
        {
            if(visited[i] == 0)
            {
                helper(edges,visited,group,flag,i);
            }
        }
        return flag;
    }

    void helper(vector<vector<int>> &edges,vector<int> &visited,unordered_map<int,int> &group,bool &flag,int curr)
    {
        if(flag == false)
        {
            return;
        }
        visited[curr] = 1;
        if(group[curr] == 0)
        {
            group[curr] = 1;
        }
        for(int i:edges[curr])
        {
            if(group[curr] == group[i])
            {
                flag = false;
                return;
            }
            if(visited[i] == 0)
            {
                visited[i] = 1;
                if(group[curr] == 1)
                {
                    group[i] = 2;
                }
                else
                {
                    group[i] = 1;
                }
                helper(edges,visited,group,flag,i);
                if(flag == false)
                {
                    return;
                }
            }
        }
        return;
    }
};