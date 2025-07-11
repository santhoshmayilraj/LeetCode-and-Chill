class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0;
        for(int i=0;i<capacity.size();i++)
        {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i:capacity)
        {
            if(i==0)
            {
                count++;
            }
            else 
            {
                if(i <= additionalRocks)
                {
                    count++;
                    additionalRocks -= i;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};