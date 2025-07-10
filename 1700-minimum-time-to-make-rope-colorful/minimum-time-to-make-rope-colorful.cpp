class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int temp = neededTime[0];
        int max_val = neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i] != colors[i-1])
            {
                ans += temp-max_val;
                temp = 0;
                max_val = 0;
            }
            temp += neededTime[i];
            max_val = max(max_val,neededTime[i]);        
        }
        ans += temp-max_val;
        return ans;
    }
};