class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> distance(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        distance[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
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
                int new_x = dx[i] + curr_x;
                int new_y = dy[i] + curr_y;
                if(new_x < 0 or new_x >= heights.size() or new_y < 0 or new_y >= heights[0].size())
                {
                    continue;
                }
                int distance_current = max(curr_distance,abs(heights[curr_x][curr_y] - heights[new_x][new_y]));
                if(distance[new_x][new_y] > distance_current)
                {
                    distance[new_x][new_y] = distance_current;
                    pq.push({distance[new_x][new_y],new_x,new_y});
                }
            }
        }
        return distance[heights.size()-1][heights[0].size()-1];
    }
};