class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for(vector<int> i:edges)
        {
            int u = i[0];
            int v = i[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<bool> visited(n);
        helper(adj,cost,count,0,visited);
        return count;
    }

    long long helper(vector<vector<int>> &adj,vector<int> &cost,int &count,int curr,vector<bool> &visited)
    {
        vector<long long> temp;
        visited[curr] = true;
        long long max_element = 0;
        for(int i:adj[curr])
        {
            if(visited[i])
            {
                continue;
            }
            long long curr_elem = helper(adj,cost,count,i,visited);
            max_element = max(curr_elem,max_element);
            temp.push_back(curr_elem);
        }
        for(long long i:temp)
        {
            if(i != max_element)
            {
                count++;
            }
        }
        return max_element + cost[curr];
    }
};