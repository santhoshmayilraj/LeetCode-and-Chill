class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start_val = intervals[0][0];
        int end_val = intervals[0][1];
        vector<vector<int>> ans;
        for(vector<int> i:intervals)
        {
            int curr_start = i[0];
            int curr_end = i[1];
            if(curr_start > end_val)
            {
                ans.push_back({start_val,end_val});
                start_val = curr_start;
                end_val = curr_end;
            }
            else
            {
                end_val = max(end_val,curr_end);
            }
        }
        ans.push_back({start_val,end_val});
        return ans;
    }
};