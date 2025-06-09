class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans(0);
        queue<int> q;
        for(int i:initialBoxes)
        {
            q.push(i);
        }
        int prev = -1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(prev == curr)
            {
                break;
            }
            prev = curr;
            if(!status[curr])
            {
                q.push(curr);
                continue;
            }
            ans+= candies[curr];
            for(int i:keys[curr])
            {
                status[i] = 1;
            }
            for(int i:containedBoxes[curr])
            {
                q.push(i);
            }
        }
        return ans;
    }
};