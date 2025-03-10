class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
        int l(0),r(0),ans(0);
        bool flag = true;
        while(r<colors.size())
        {
            if(r!=0 and colors[r] == colors[r-1])
            {
                flag = false;
            }
            if(flag == false)
            {
                l = r;
                flag = true;
            }
            while(r-l+1 > k)
            {
                l++;
            }
            if(r-l+1 == k)
            {
                ans++;
            }
            r++;
        }
        return ans;
    }
};