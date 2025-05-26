class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const vector<int>& i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        distance[k] = 0;
        pq.push({0, k}); // {distance, node}

        while (!pq.empty()) {
            vector<int> curr = pq.top(); pq.pop();
            int curr_distance = curr[0];
            int curr_node = curr[1];

            if (curr_distance > distance[curr_node]) continue; // Skip outdated entries

            for (const pair<int, int>& j : adj[curr_node]) {
                int temp_node = j.first;
                int temp_weight = j.second;

                if (distance[temp_node] > distance[curr_node] + temp_weight) {
                    distance[temp_node] = distance[curr_node] + temp_weight;
                    pq.push({distance[temp_node], temp_node});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};
