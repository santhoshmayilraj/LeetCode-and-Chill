class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(2*n+1,0);
        int pref_sum = 0;
        long long ans = 0;
        pref[n] = 1;
        int cnt = n;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                pref_sum += pref[cnt];
                cnt++;
                pref[cnt]++;
            }else{
                cnt--;
                pref_sum -= pref[cnt];
                pref[cnt]++;
            }
            ans += pref_sum;
        }
        return ans;
    }
};