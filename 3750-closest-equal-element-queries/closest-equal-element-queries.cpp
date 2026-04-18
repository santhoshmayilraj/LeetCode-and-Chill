class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> hash;
        vector<int> ans(nums.size(),INT_MAX);

        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]].push_back(i);

            if(hash[nums[i]].size() > 1)
            {
                vector<int>& curr_vec = hash[nums[i]];

                int prev_idx = curr_vec[curr_vec.size()-2];
                int temp = abs(prev_idx - i);
                temp = min((int)nums.size()-temp, temp);

                ans[prev_idx] = min(ans[prev_idx], temp);
                ans[i] = min(ans[i], temp);
            }
        }

        for(auto i:hash)
        {
            int curr = i.first;
            vector<int>& curr_vec = hash[curr];
            if(curr_vec.size() < 2)
            {
                continue;
            }
            int first = curr_vec[0];
            int last = curr_vec[curr_vec.size()-1];

            int temp = abs(first - last);
            temp = min((int)nums.size()-temp, temp);

            ans[first] = min(ans[first], temp);
            ans[last] = min(ans[last], temp);
        }

        vector<int> ans_arr(queries.size());

        for(int i=0;i<queries.size();i++)
        {
            if(ans[queries[i]] != INT_MAX)
            {
                ans_arr[i] = ans[queries[i]];
            }
            else
            {
                ans_arr[i] = -1;
            }
        }

        return ans_arr;
    }
};