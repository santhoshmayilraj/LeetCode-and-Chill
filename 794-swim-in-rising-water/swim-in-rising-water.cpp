class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        distance[0][0] = grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({distance[0][0],0,0});
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            int curr_distance = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];
            for(int i=0;i<4;i++)
            {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];
                if(new_x < 0 or new_x >= grid.size() or new_y < 0 or new_y >= grid[0].size())
                {
                    continue;
                } 
                int weight = max(grid[new_x][new_y],curr_distance);
                if(distance[new_x][new_y] > weight)
                {
                    distance[new_x][new_y] = weight;
                    pq.push({distance[new_x][new_y],new_x,new_y});
                }
            }
        }
        return distance[grid.size()-1][grid[0].size()-1];        
    }
};