class Solution {
public:

    int helper(vector<int>&arr,int d,int i,vector<int>& dp)
    {
        int curr = arr[i];
        int ans = 1;
        for(int j=0;j<d;j++)
        {
            int curr_idx = i+j+1;
            if(curr_idx < arr.size() and arr[curr_idx] < curr)
            {
                if(dp[curr_idx] != -1)
                {
                    ans = max(ans,dp[curr_idx]+1);
                }
                else
                {
                    int temp;
                    temp = helper(arr,d,curr_idx,dp);
                    ans = max(ans,temp+1);
                }
            }
            else
            {
                break;
            }
        }

        for(int j=0;j<d;j++)
        {
            int curr_idx = i-j-1;
            if(curr_idx >= 0 and arr[curr_idx] < curr)
            {
                if(dp[curr_idx] != -1)
                {
                    ans = max(ans,dp[curr_idx]+1);
                }
                else
                {
                    int temp;
                    temp = helper(arr,d,curr_idx,dp);
                    ans = max(ans,temp+1);
                }
            }
            else
            {
                break;
            }
        }

        dp[i] = ans;
        return ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int max_jumps = 1;
        vector<int> dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++)
        {
            max_jumps = max(max_jumps,helper(arr,d,i,dp));
        }
        return max_jumps;
    }
};