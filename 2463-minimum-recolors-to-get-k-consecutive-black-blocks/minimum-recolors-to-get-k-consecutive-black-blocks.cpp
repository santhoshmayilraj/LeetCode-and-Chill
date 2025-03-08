class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if(blocks.size()<k)
        {
            return -1;
        }
        int l(0),r(0);
        int countw(0),countr(0);
        int ans = INT_MAX;
        while(r<blocks.size())
        {
            if(blocks[r] == 'W')
            {
                countw++;
            }
            else
            {
                countr++;
            }

            while(r-l+1>k)
            {
                if(blocks[l] == 'W')
                {
                    countw--;
                }
                else
                {
                    countr--;
                }
                l++;
            }
            if(r-l+1 == k)
            {
                ans = min(ans,countw);
            }
            r++;
        }
        return ans;
        
    }
};