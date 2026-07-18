class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        int curr_begin = INT_MAX;
        int curr_end = INT_MIN;
        vector<vector<int>> ans;
        for(vector<int> &i:intervals){
            if(curr_begin <= i[0] && curr_end >= i[1]){
                continue;
            }
            curr_begin = i[0];
            curr_end = i[1];
            ans.push_back({i[0],i[1]});
        }
        return ans.size();
    }
};