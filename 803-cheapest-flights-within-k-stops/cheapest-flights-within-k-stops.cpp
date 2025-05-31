class Solution {
    // solving the problem using Bellman - Ford Algorithm 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        for(int i=0;i<k+1;i++)
        {
            vector<int> temp = distance;
            for(vector<int> j:flights)
            {
                int u = j[0];
                int v = j[1];
                int w = j[2];
                if(distance[u] != INT_MAX and temp[v] > distance[u] + w)
                {
                    temp[v] = distance[u] + w;
                }
            }
            distance = temp;
        }
        return distance[dst] == INT_MAX ? -1:distance[dst];
    }
};