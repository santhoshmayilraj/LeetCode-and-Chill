class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        for(int i:bills)
        {
            if(i==5)
            {
                change[0]++;
            }
            else if(i==10)
            {
                if(change[0] == 0)
                {
                    return false;
                }
                change[0]--;
                change[1]++;
            }
            else
            {
                if(change[0] < 1)
                {
                    return false;
                }
                else if(change[1] > 0)
                {
                    change[1]--;
                    change[0]--;
                    change[2]++;
                }
                else if(change[0] > 2)
                {
                    change[0]--;
                    change[0]--;
                    change[0]--;
                    change[2]++;
                }
                else
                {
                    return false;
                }
            }
        }       
        return true;        
    }
};