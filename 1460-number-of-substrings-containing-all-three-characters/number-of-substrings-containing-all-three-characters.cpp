class Solution {
public:
    int numberOfSubstrings(string s) {
        int l(0),r(0);
        int count(0);
        int ans(0);
        unordered_map<int,int> hash;
        while(r<s.size())
        {
            hash[s[r]]++;
            if(hash[s[r]] == 1)
            {
                count++;
            }
            if(count == 3)
            {
                int temp2 = s.size() - r;
                int temp = 0;
                while(count == 3)
                {
                    temp++;
                    if(hash[s[l]] == 1)
                    {
                        count--;
                    }
                    hash[s[l]]--;
                    l++;
                }
                ans+= temp*temp2;
            }
            r++;
        } 
        return ans;       
    }
};