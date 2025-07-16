class Solution {
public:
    bool ispossible(vector<int> &bloomDay,int m,int k,int curr)
    {
        int l(0),r(0);
        int count = 0;
        while(r<bloomDay.size())
        {
            if(count >= m)
            {
                return true;
            }
            if(bloomDay[r] >= curr )
            {
                l = r+1;
            }
            if( r-l+1 == k)
            {
                count++;
                l = r+1;
            }
            r++;
        }
        if(count >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int l = 0; 
        long long sz = bloomDay.size();
        if(sz < 1ll*m*k)
        {
            return -1;
        }       
        if(sz == m*k)
        {
            return r;
        }
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(!ispossible(bloomDay,m,k,mid))
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return r;
    }
};