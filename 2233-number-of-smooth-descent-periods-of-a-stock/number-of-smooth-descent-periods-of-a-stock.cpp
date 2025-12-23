class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int l(0),r(1);
        while(r<prices.size())
        {
            if(prices[r]-prices[r-1] == -1)
            {
                ans += r-l+1;
            }
            else
            {
                l = r;
                ans += r-l+1;
            }
            r++;
        }
        return ans;
    }
};