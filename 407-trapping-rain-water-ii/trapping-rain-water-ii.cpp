class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if (n < 3 || m < 3) return 0; // Added base case check

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,-1,1};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> heap;
        for(int i=0;i<n;i++)
        {
            heap.push({heightMap[i][0],i,0});
            heap.push({heightMap[i][m-1],i,m-1});  
            visited[i][0] = true;
            visited[i][m-1] = true;          
        }

        for(int i=0;i<m;i++)
        {
            if (!visited[0][i]) { // Avoid adding corners twice
                heap.push({heightMap[0][i],0,i});
                visited[0][i] = true;
            }
            if (!visited[n-1][i]) { // Avoid adding corners twice
                heap.push({heightMap[n-1][i],n-1,i}); // Fixed Bug 1
                visited[n-1][i] = true;
            }
        }

        int ans = 0;

        while(!heap.empty())
        {
            vector<int> curr = heap.top();
            heap.pop();

            int curr_height = curr[0];
            int curr_x = curr[1];
            int curr_y = curr[2];
            for(int i=0;i<4;i++)
            {
                int new_x = curr_x + x[i]; 
                int new_y = curr_y + y[i]; 

                if(new_x < 0 or new_x >= n or new_y < 0 or new_y >= m or visited[new_x][new_y]) 
                {
                    continue;
                }
                visited[new_x][new_y] = true;
                if(heightMap[new_x][new_y] < curr_height)
                {
                    ans += curr_height - heightMap[new_x][new_y];
                }
                
                heap.push({max(curr_height, heightMap[new_x][new_y]), new_x, new_y}); 
            }
        }
        return ans;
    }
};