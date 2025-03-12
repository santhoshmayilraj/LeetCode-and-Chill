class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count_neg(0),count_pos(0);
        for(int i:nums)
        {
            if(i<0)
            {
                count_neg++;
            }
            if(i>0)
            {
                count_pos++;
            }
        }
        return max(count_neg,count_pos);
    }
};