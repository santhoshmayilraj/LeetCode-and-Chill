class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid.empty() || grid[0].empty()) return false;

        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        distance[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({distance[0][0], 0, 0});

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int curr_dist = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];

            for (int i = 0; i < 4; i++) {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                if (new_x < 0 || new_x >= distance.size() || new_y < 0 || new_y >= distance[0].size()) {
                    continue;
                }

                if (distance[new_x][new_y] > distance[curr_x][curr_y] + grid[new_x][new_y]) {
                    distance[new_x][new_y] = distance[curr_x][curr_y] + grid[new_x][new_y];
                    pq.push({distance[new_x][new_y], new_x, new_y});
                }
            }
        }

        return distance.back().back() < health;
    }
};
