class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 1;
        queue<int> temp;
        temp.push(0);
        vector<int> visited(rooms.size());
        visited[0] = 1; 
        while(!temp.empty())
        {
            int n = temp.size();
            for(int i=0;i<n;i++)
            {
                int curr = temp.front();
                temp.pop();
                for(int j:rooms[curr])
                {
                    if(visited[j]==0)
                    {
                        temp.push(j);
                        count++;
                        visited[j] = 1;
                    }
                }
            }
        }
        return count == rooms.size();  
    }
};