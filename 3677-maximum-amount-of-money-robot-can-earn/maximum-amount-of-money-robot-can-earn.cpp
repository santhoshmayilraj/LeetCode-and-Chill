class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        const int MIN_VAL = -1e9; 
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, MIN_VAL)));
        
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) continue;
                
                int val = coins[r][c];
                
                for (int k = 0; k < 3; ++k) {
                    
                    int prev_max_k = MIN_VAL;
                    if (r > 0) prev_max_k = max(prev_max_k, dp[r - 1][c][k]);
                    if (c > 0) prev_max_k = max(prev_max_k, dp[r][c - 1][k]);
                    
                    if (prev_max_k != MIN_VAL) {
                        dp[r][c][k] = prev_max_k + val;
                    }
                    
                    if (val < 0 && k > 0) {
                        int prev_max_k_minus_1 = MIN_VAL;
                        
                        if (r > 0) prev_max_k_minus_1 = max(prev_max_k_minus_1, dp[r - 1][c][k - 1]);
                        if (c > 0) prev_max_k_minus_1 = max(prev_max_k_minus_1, dp[r][c - 1][k - 1]);
                        
                        if (prev_max_k_minus_1 != MIN_VAL) {
                            dp[r][c][k] = max(dp[r][c][k], prev_max_k_minus_1 + 0);
                        }
                    }
                }
            }
        }
        
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};