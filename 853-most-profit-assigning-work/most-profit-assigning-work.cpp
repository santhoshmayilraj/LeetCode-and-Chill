class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans(0);
        vector<pair<int,int>> temp(difficulty.size());
        for(int i=0;i<difficulty.size();i++)
        {
            temp[i].first = profit[i];
            temp[i].second = difficulty[i];
        }

        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        sort(worker.begin(),worker.end());
        reverse(worker.begin(),worker.end());

        int l(0),r(0);
        while(l<temp.size() and r<worker.size())
        {
            if(worker[r] >= temp[l].second)
            {
                ans += temp[l].first;
                r++;
            }
            else
            {
                l++;
            }
        }
        return ans;        
    }
};