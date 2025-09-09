class Solution {
public:
    int MOD = 1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1, -1); 
        return helper(1, n, delay, forget, dp);
    }

    long long helper(int curr, int n, int delay, int forget, vector<long long>& dp) {
        if (curr > n) return 0; 
        if (dp[curr] != -1) return dp[curr];

        long long ans = 0;
        if (curr + forget > n) {
            ans = 1;  
        }
        for (int day = curr + delay; day <= min(n, curr + forget - 1); day++) {
            ans = (ans + helper(day, n, delay, forget, dp)) % MOD;
        }

        return dp[curr] = ans;
    }
};
