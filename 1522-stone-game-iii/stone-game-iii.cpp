class Solution {
public:
    int dfs(vector<int>& stoneValue, vector<int>& dp, int curr) {
        int n = stoneValue.size();

        if (curr >= n) {
            return 0;
        }

        if (dp[curr] != INT_MIN) {
            return dp[curr];
        }

        int curr_sum = 0;
        int curr_ans = INT_MIN;
        for (int i = curr; i < min(n, curr + 3); i++) {
            curr_sum += stoneValue[i];

            int opponent = dfs(stoneValue, dp, i + 1);

            curr_ans = max(curr_ans, curr_sum - opponent);
        }

        return dp[curr] = curr_ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int difference = dfs(stoneValue, dp, 0);

        if (difference == 0) {
            return "Tie";
        }
        else if (difference > 0) {
            return "Alice";
        }
        else {
            return "Bob";
        }
    }
};