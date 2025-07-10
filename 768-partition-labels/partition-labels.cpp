class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> interval(26,vector<int>(2,INT_MAX));
        for(int i=0;i<s.size();i++)
        {
            if(interval[s[i]-'a'][0] == INT_MAX)
            {
                interval[s[i] - 'a'][0] = i;
            }
            interval[s[i] - 'a'][1] = i;
        }
        sort(interval.begin(),interval.end());
        int start_val = interval[0][0];
        int end_val = interval[0][1];
        vector<int> ans;
        for(vector<int> i:interval)
        {
            int curr_val = i[0];
            int curr_end = i[1];
            if(curr_val == INT_MAX)
            {
                break;
            }
            if(curr_val > end_val)
            {
                ans.push_back(end_val - start_val+1);
                start_val = curr_val;
                end_val = curr_end; 
            }
            else 
            {
                end_val = max(end_val,curr_end);
            }
        }
        ans.push_back(end_val - start_val+1);
        return ans;
    }
};