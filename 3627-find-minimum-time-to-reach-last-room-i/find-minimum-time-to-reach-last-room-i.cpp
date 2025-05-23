class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> distance(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        distance[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        while(!pq.empty())
        {
            vector<int> curr;
            curr = pq.top();
            pq.pop();
            int curr_time = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];
            for(int j=0;j<4;j++)
            {
                int new_x = curr_x + dx[j];
                int new_y = curr_y + dy[j];
                if(new_x < 0 or new_x >= moveTime.size() or new_y < 0 or new_y >= moveTime[0].size())
                {
                    continue;
                }
                int new_time;
                new_time = max(distance[curr_x][curr_y]+1,moveTime[new_x][new_y]+1);
                if(new_time < distance[new_x][new_y])
                {
                    distance[new_x][new_y] = new_time;
                    pq.push({new_time,new_x,new_y});
                }
            }    
        } 
        return distance[distance.size()-1][distance[0].size()-1]; 
    }
};