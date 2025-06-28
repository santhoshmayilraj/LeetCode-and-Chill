class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l(0),r(0);
        unordered_map<char,int> hash;
        int count = 0;
        while(r<s.size())
        {
            hash[s[r]]++;
            if(hash[s[r]]>1 or count)
            {
                if(hash[s[r]]>1)
                {
                    count++;
                }
                if(hash[s[l]]>1)
                {
                    count--;
                }
                hash[s[l]]--;
                l++;
            }
            r++;
        }
        return r-l;
    }
};