class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(int i=0;i<bookings.size();i++)
        {
            ans[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1] < n)
            {
                ans[bookings[i][1]] -= bookings[i][2];
            } 
        }        
        for(int i=1;i<n;i++)
        {
            ans[i] = ans[i-1] + ans[i];
        }
        return ans;
    }
};