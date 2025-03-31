class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int indegree_count = n;
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            if (indegree[edges[i][1]] == 0) {
                indegree_count--;
            }
            indegree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
        }

        if (indegree_count != 1) {
            return -1;  
        }

        vector<bool> visited(n, false);
        queue<int> temp;
        int count = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans = i;
                temp.push(i);
                visited[i] = true;
                count++;
                break;  
            }
        }
        while (!temp.empty()) {
            int sz = temp.size();
            for (int i = 0; i < sz; i++) {
                int curr = temp.front();
                temp.pop();
                for(int j:graph[curr])
                {
                    if(visited[j] == 0)
                    {
                        visited[j] = true;
                        temp.push(j);
                        count++;
                    }
                }
            }
        }
        if (count == n) {
            return ans;
        }
        return -1;
    }
};
