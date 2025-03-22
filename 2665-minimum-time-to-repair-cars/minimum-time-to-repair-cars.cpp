class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans(0);
        long long time = *min_element(ranks.begin(),ranks.end());
        time = time*cars*cars;
        long long l = 0;
        while(l<=time)
        {
            long long mid = (l+time)/2;
            long long temp = 0;
            for(int i:ranks)
            {
                temp += sqrt(mid/i);
            }
            if(temp >= cars)
            {
                ans = mid;
                time = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }   
        return ans;        
        
    }
};