class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rowsz = grid.size();
        int colsz = grid[0].size();
        if(grid[0][0] == 1)
        {
            return -1;
        }
        vector<vector<int>> distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        distance[0][0] = 1;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({1,0,0});
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            int curr_weight = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];
            if(curr_x+1 < rowsz and grid[curr_x+1][curr_y] == 0 and distance[curr_x+1][curr_y] > curr_weight + 1)
            {
                distance[curr_x+1][curr_y] = curr_weight + 1;
                pq.push({distance[curr_x+1][curr_y],curr_x+1,curr_y});
            }
            if(curr_x-1 >=0 and grid[curr_x-1][curr_y] == 0 and distance[curr_x-1][curr_y] > curr_weight + 1)
            {
                distance[curr_x-1][curr_y] = curr_weight + 1;
                pq.push({distance[curr_x-1][curr_y],curr_x-1,curr_y});
            }
            if(curr_y+1 < colsz and grid[curr_x][curr_y+1] == 0 and distance[curr_x][curr_y+1] > curr_weight + 1)
            {
                distance[curr_x][curr_y+1] = curr_weight + 1;
                pq.push({distance[curr_x][curr_y+1],curr_x,curr_y+1});
            }
            if(curr_y-1 >= 0 and grid[curr_x][curr_y-1] == 0 and distance[curr_x][curr_y-1] > curr_weight + 1)
            {
                distance[curr_x][curr_y-1] = curr_weight + 1;
                pq.push({distance[curr_x][curr_y-1],curr_x,curr_y-1});
            }
            if(curr_x+1 < rowsz and curr_y+1 < colsz and grid[curr_x+1][curr_y+1] == 0 and distance[curr_x+1][curr_y+1] > curr_weight + 1)
            {
                distance[curr_x+1][curr_y+1] = curr_weight + 1;
                pq.push({distance[curr_x+1][curr_y+1],curr_x+1,curr_y+1});
            }
            if(curr_x+1 < rowsz and curr_y-1 >= 0 and grid[curr_x+1][curr_y-1] == 0 and distance[curr_x+1][curr_y-1] > curr_weight + 1)
            {
                distance[curr_x+1][curr_y-1] = curr_weight + 1;
                pq.push({distance[curr_x+1][curr_y-1],curr_x+1,curr_y-1});
            }
            if(curr_x-1 >= 0 and curr_y-1 >= 0 and grid[curr_x-1][curr_y-1] == 0 and distance[curr_x-1][curr_y-1] > curr_weight + 1)
            {
                distance[curr_x-1][curr_y-1] = curr_weight + 1;
                pq.push({distance[curr_x-1][curr_y-1],curr_x-1,curr_y-1});
            }
            if(curr_x-1 >= 0 and curr_y+1 < colsz and grid[curr_x-1][curr_y+1] == 0 and distance[curr_x-1][curr_y+1] > curr_weight + 1)
            {
                distance[curr_x-1][curr_y+1] = curr_weight + 1;
                pq.push({distance[curr_x-1][curr_y+1],curr_x-1,curr_y+1});
            }
        }
        if(distance[rowsz-1][colsz-1] == INT_MAX)
        {
            return -1;
        }
        return distance[rowsz-1][colsz-1];
    }
};