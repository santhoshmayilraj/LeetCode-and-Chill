class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr = image[sr][sc];
        image[sr][sc] = color;
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>> temp;
        temp.push({sr,sc});
        while(!temp.empty())
        {
            int sz = temp.size();
            for(int i=0;i<sz;i++)
            {
                int x = temp.front().first;
                int y = temp.front().second;
                temp.pop();
                if(x-1 >=0 and visited[x-1][y] == 0 and image[x-1][y] == curr)
                {
                    image[x-1][y] = color;
                    temp.push({x-1,y});
                    visited[x-1][y] = 1;
                }
                if(x+1 < image.size() and visited[x+1][y] == 0 and image[x+1][y] == curr)
                {
                    image[x+1][y] = color;
                    temp.push({x+1,y});
                    visited[x+1][y] = 1;
                }
                if(y+1 < image[0].size() and visited[x][y+1] == 0 and image[x][y+1] == curr)
                {
                    image[x][y+1] = color;
                    temp.push({x,y+1});
                    visited[x][y+1] = 1;
                }
                if(y-1 >=0 and visited[x][y-1] == 0 and image[x][y-1] == curr)
                {
                    image[x][y-1] = color;
                    temp.push({x,y-1});
                    visited[x][y-1] = 1;
                }
            }
        }
        return image;
    }
};