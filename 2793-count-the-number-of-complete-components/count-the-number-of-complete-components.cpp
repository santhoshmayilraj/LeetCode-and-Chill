class Solution {
public:

    void dfs(vector<vector<int>>& graph,
             vector<int>& visited,
             int curr,
             vector<int>& component) {

        if (visited[curr] != -1)
            return;

        visited[curr] = 1;
        component.push_back(curr);

        for (int next : graph[curr]) {
            dfs(graph, visited, next, component);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (vector<int>& curr : edges) {
            graph[curr[0]].push_back(curr[1]);
            graph[curr[1]].push_back(curr[0]);
        }

        vector<int> visited(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i] == -1) {

                vector<int> component;

                dfs(graph, visited, i, component);

                int count = component.size();

                bool flag = true;

                for (int node : component) {

                    if (graph[node].size() != count - 1) {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    ans++;
            }
        }

        return ans;
    }
};