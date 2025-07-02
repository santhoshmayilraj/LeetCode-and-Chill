class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> hash;
        for(int i=0;i<arr.size();i++)
        {
            hash[arr[i]].push_back(i);
        }
        vector<bool> visited(arr.size(),false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int level = 0;
        while(!q.empty() and level<arr.size()-1)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int curr = q.front();
                q.pop();
                if(curr == arr.size()-1)
                {
                    return level;
                }
                if(curr-1 >= 0 and !visited[curr-1])
                {
                    q.push(curr-1);
                    visited[curr-1] = true;
                }
                if(curr+1 <arr.size() and !visited[curr+1])
                {
                    q.push(curr+1);
                    visited[curr+1] = true;
                }
                for(int j:hash[arr[curr]])
                {
                    if(!visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                    }  
                }
                hash[arr[curr]].clear();
            }
            level++;
        }
        return level;
    }
};