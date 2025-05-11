class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int temp =0;
        for(int i:arr)
        {
            if(i%2 ==0)
            {
                temp = 0;
            }
            else
            {
                if(temp == 2)
                {
                    return true;
                }
                temp++;
            }
        }
        return false;
        
    }
};