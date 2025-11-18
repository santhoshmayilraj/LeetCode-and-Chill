class Solution {
public:
    int MOD = 1e9+7;
    int numSub(string s) {
        long long ans = 0;
        long long count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '0')
            {
                ans += ((count*(count+1))/2)%MOD;
                count = 0;
            }
            else
            {
                count++;
            }
        }
        ans += ((count*(count+1))/2)%MOD;
        return ans;
    }
};