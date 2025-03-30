class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        unordered_map<int,int> indegree;
        vector<vector<int>> indegree_graph(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            indegree[i] = graph[i].size();
            for(int j:graph[i])
            {
                indegree_graph[j].push_back(i);
            }
        }
        queue<int> temp;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                temp.push(i);
                ans.push_back(i);
            }
        }
        int prev = -1;
        int sz = ans.size();
        while(!temp.empty())
        {
            if(prev == sz)
            {
                sort(ans.begin(),ans.end());
                return ans;
            }
            int curr_sz = temp.size();
            for(int i=0;i<curr_sz;i++)
            {
                int curr = temp.front();
                temp.pop();
                for(int k:indegree_graph[curr])
                {
                    indegree[k]--;
                    if(indegree[k]==0)
                    {
                        ans.push_back(k);
                        temp.push(k);
                    }
                }        
            }
            prev = sz;
            sz = ans.size();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};