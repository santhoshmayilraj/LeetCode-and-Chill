class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini(INT_MAX), maxi(INT_MIN);
        int min_ind(-1), max_ind(-1);
        int count = 0;
        for(int i : nums) {
            if(mini > i) {
                mini = i;
                min_ind = count;
            }
            if(maxi < i) {
                maxi = i;
                max_ind = count;
            }
            count++;
        }
        int min_index = min(min_ind, max_ind);
        int max_index = max(min_ind, max_ind);
        
        int n = (int)nums.size();
        
        int ans = min_index + 1 + (n - max_index);
        ans = min({ans, max_index + 1, n - min_index});
        
        return ans;
    }
};