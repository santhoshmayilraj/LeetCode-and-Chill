class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l(0),r(tokens.size()-1);
        int ans = 0;
        int temp = 0;
        while(l<=r)
        {
            if(tokens[l] <= power)
            {
                temp++;
                power -= tokens[l];
                ans = max(ans,temp);
                l++;
            }
            else if(temp > 0)
            {
                temp--;
                power+= tokens[r];
                r--;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};