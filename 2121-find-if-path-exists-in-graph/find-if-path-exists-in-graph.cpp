class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
        {
            return true;
        }
        vector<vector<int>> edge(n);
        for(int i=0;i<edges.size();i++)
        {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        bool flag = false;
        helper(edge,visited,source,destination,flag);
        return flag;
    }

    void helper(vector<vector<int>> &edge,vector<int> &visited,int source,int destination,bool &flag)
    {
        visited[source] = 1;
        if(flag == true)
        {
            return;
        }
        for(int i:edge[source])
        {
            if(i==destination)
            {
                flag = true;
                return;
            }
            if(visited[i]==0)
            {
                helper(edge,visited,i,destination,flag);
                if(flag)
                {
                    return;
                }
            }
        }
        return;
    }
};