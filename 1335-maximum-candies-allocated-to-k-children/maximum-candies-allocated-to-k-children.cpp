class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        if(candies.size() == 0)
        {
            return 0;
        }
        sort(candies.begin(),candies.end());
        int ans(0),l(0),r(candies[candies.size()-1]);
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long temp = 0;
            int i = candies.size()-1;
            while(i>=0 and mid !=0 and temp < k)
            {
                temp += (candies[i]/mid);
                i--;
            }
            if(mid == 0)
            {
                l = mid+1;
            }
            else if(temp >= k)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }    
        return ans;    
    }
};