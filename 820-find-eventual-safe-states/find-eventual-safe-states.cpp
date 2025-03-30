class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==0)
            {
                helper(visited,ans,i,graph);
            }
        }   
        sort(ans.begin(),ans.end());     
        return ans;
    }

    void helper(vector<int> &visited,vector<int> &ans,int curr,vector<vector<int>> &graph)
    {
        if(visited[curr]!=0)
        {
            return;
        }
        visited[curr] = 1;
        for(int i:graph[curr])
        {
            if(visited[i] == 1)
            {
                return;
            }
            if(visited[i] == 0)
            {
                helper(visited,ans,i,graph);
                if(visited[i] == 1)
                {
                    return;
                }
            }
        }
        visited[curr] = 2;
        ans.push_back(curr);
    }
};