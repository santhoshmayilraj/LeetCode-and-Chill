class Solution {
public:
    int dfs(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int curr_score = INT_MIN;
        curr_score = max(curr_score, nums[j] - dfs(nums,i,j-1,dp));
        curr_score = max(curr_score, nums[i] - dfs(nums,i+1,j,dp));
        return curr_score;
    }
    bool predictTheWinner(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        for(int k=0;k<nums.size();k++){
            dp[k][k] = nums[k];
        }
        int ans = dfs(nums,i,j,dp);
        return ans > -1;
    }
};