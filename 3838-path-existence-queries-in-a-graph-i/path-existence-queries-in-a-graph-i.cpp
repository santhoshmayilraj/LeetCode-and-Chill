class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> check_array(nums.size(),0);
        int count = 0;
        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1] <= maxDiff)){
                check_array[i] = count;
            }else{
                check_array[i] = ++count;
            }
        }
        vector<bool> ans(queries.size());
        int i = 0;
        for(vector<int> &curr:queries){
            int start = curr[0];
            int end = curr[1];
            ans[i] = (check_array[start] == check_array[end]);
            i++;
        }
        return ans;
    }
};