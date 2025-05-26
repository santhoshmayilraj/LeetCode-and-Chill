class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Priority queue: {cost, current_node, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        // We store visited[node][stops] = min cost
        vector<vector<int>> visited(n, vector<int>(k + 2, INT_MAX));
        visited[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top(); pq.pop();

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto& [nei, price] : adj[node]) {
                int new_cost = cost + price;
                if (new_cost < visited[nei][stops + 1]) {
                    visited[nei][stops + 1] = new_cost;
                    pq.emplace(new_cost, nei, stops + 1);
                }
            }
        }

        return -1;
    }
};
