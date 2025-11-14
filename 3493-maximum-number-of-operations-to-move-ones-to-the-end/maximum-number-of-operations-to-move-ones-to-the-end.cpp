class Solution {
public:
    int maxOperations(string s) {
        bool flag = true;
        int ans = 0;
        int count_o = 0;
        int count_z = 0;
        for(int i=0;i<s.size();i++)
        {
            if(flag and s[i] == '1')
            {
                count_o++;
            }
            else if(!flag and s[i] == '1')
            {
                ans += count_o;
                count_o++;
                flag = true;
                count_z = 0;
            }
            else
            {
                count_z++;
                flag = false;
            }
        }
        if(!flag)
        {
            ans+= count_o;
        }
        return ans;
    }
};