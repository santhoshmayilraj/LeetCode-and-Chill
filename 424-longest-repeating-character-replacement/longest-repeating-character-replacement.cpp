class Solution {
public:
    int characterReplacement(string s, int k) {
        int r(0),l(0);
        int max_freq(0);
        unordered_map<char,int> hash;
        while(r<s.size())
        {
            hash[s[r]]++;
            max_freq = max(max_freq,hash[s[r]]);
            if((r-l+1) - max_freq > k)
            {
                hash[s[l]]--;
                l++;
            }
            r++;
        }
        return r-l;
    }
};