class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        for(int i:cardPoints)
        {
            score += i;
        }
        if(k==cardPoints.size())
        {
            return score;
        }
        int l(0),r(0);
        int ans = INT_MAX;
        int temp = 0;
        while(r<cardPoints.size())
        {
            temp += cardPoints[r];
            while(r-l+1 > cardPoints.size()-k)
            {
                temp -= cardPoints[l];
                l++;
            }
            if(r-l+1 == cardPoints.size()-k)
            {
                ans = min(ans,temp);
            }
            r++;
        }
        return score - ans;        
    }
};