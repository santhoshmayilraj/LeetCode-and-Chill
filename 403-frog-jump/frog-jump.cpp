class Solution { // this is the brute force recursive solution - even approaching to this was kind of hard - so whenever try to solve a question understand the goal of the question , the base case of the question , how to relate the goal and the base case


// approach - top down memoization 
public:
    bool canCross(vector<int>& stones) {
        vector<int> jumps = {-1,0,1};
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        helper(0, 0, stones, jumps,dp);
        return dp[0][0];
    }

    int helper(int curr_index, int curr_jump, vector<int> &stones, vector<int> &jumps,vector<vector<int>> &dp)
    {
        if(curr_index == stones.size() - 1)
        {
            return 1;
        }
        if(dp[curr_index][curr_jump] != -1)
        {
            return dp[curr_index][curr_jump];
        }
        
        for(int i : jumps)
        {
            int new_jump = curr_jump + i;
            if(new_jump <= 0)
            {
                continue;
            }
            int next_pos = stones[curr_index] + new_jump;
            for(int j = curr_index + 1; j < stones.size(); j++)
            {
                if(stones[j] == next_pos)
                {
                    dp[curr_index][curr_jump] = helper(j, new_jump, stones, jumps,dp);
                    if(dp[curr_index][curr_jump] ==1)
                    {
                        return 1;
                    }
                }
                else if(stones[j] > next_pos)
                {
                    break;
                }

            }
        }
        dp[curr_index][curr_jump] = 0;
        return 0;
    }
};
