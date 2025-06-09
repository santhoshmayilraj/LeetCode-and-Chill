class Solution { // bottom-up space optimization 
public:
    int uniquePaths(int m, int n) {
        int mod = 2*(pow(10,9));
        if(m==0 and n==0)
        {
            return 0;
        }
        // normal bottom-up uses O(m*n) space complexity but right now it uses only O(n) size;
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int> curr(n,0);
            curr[0] = 1;
            for(int j=1;j<n;j++)
            {
                curr[j] = curr[j-1] + dp[j];
            }
            dp = curr;
        }
        return dp[n-1];
    }
};