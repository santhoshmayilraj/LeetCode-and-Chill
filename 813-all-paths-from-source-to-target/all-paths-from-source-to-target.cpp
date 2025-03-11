class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> visited;
        visited.push_back(0);
        for(int i=0;i<graph[0].size();i++)
        {
            visited.push_back(graph[0][i]);
            helper(visited,ans,graph);
            visited.pop_back();
        }
        return ans;
    }

    void helper(vector<int> &visited,vector<vector<int>> &ans,vector<vector<int>>& graph)
    {
        if(visited.back() == graph.size()-1)
        {
            ans.push_back(visited);
            return;
        }
        for(int i=0;i<graph[visited.back()].size();i++)
        {
            if(find(visited.begin(), visited.end(), graph[visited.back()][i]) != visited.end())
            {
                continue;
            }
            else
            {
                visited.push_back(graph[visited.back()][i]);
                helper(visited,ans,graph);
                visited.pop_back();
            }
        }
        return;
    }
};