class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> hash;
        int ans = 0;
        int count = 0;
        for(string i:words)
        {
            if(i[0] == i[1])
            {
                if(hash[i])
                {
                    hash[i]--;
                    ans+=4;
                    count--;
                }
                else
                {
                    hash[i]++;
                    count++;
                }
            }
            else 
            {
                string temp = i;
                temp[0] = i[1];
                temp[1] = i[0];
                if(hash[temp])
                {
                    hash[temp]--;
                    ans += 4;
                }  
                else
                {
                    hash[i]++;
                }
            }
        }
        if(count)
        {
            ans += 2;
        }
        return ans;
    }
};