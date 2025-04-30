class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i:nums)
        {
            if(i == 0)
            {
                continue;
            }
            int temp = log10(i);
            if(temp%2==1)
            {
                count++;
            }
        }
        return count;
    }
};