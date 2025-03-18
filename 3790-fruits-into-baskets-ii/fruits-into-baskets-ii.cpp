class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for(int i:fruits)
        {
            for(int j=0;j<baskets.size();j++)
            {
                if(baskets[j] >= i)
                {
                    baskets[j] = -1;
                    count--;
                    break;
                }
            }
            count++;
        }
        return count;        
    }
};