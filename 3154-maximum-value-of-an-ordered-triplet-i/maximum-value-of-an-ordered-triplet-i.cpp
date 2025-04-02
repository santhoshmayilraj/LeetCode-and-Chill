class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Edge case: If less than 3 elements, return 0

        vector<int> pref(n, INT_MIN);
        vector<int> suff(n, INT_MIN);
        long long ans = 0;
        int maxi = nums[0];

        // Compute pref[i] = max(nums[0] ... nums[i]) - nums[i+1]
        for (int i = 1; i < n - 1; i++) {
            pref[i] = maxi - nums[i];
            maxi = max(maxi, nums[i]);
        }

        // Compute suff[i] = max(nums[i+1] ... nums[n-1])
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            suff[i] = max(suff[i + 1], nums[i]);
        }

        // Calculate max (pref[i] * suff[i+1])
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (long long) pref[i] * suff[i + 1]);
        }

        return ans;
    }
};

