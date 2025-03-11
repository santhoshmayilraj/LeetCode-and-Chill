class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans(0);
        for(int i=0;i<word.size();i++)
        {
            unordered_map<char,int> hash;
            hash[word[i]]++;
            for(int j=i+1;j<word.size();j++)
            {
                hash[word[j]]++;
                if(hash.size()>5)
                {
                    break;
                }
                if(hash['a'] and hash['e'] and hash['i'] and hash['o'] and hash['u'])
                {
                    ans++;
                }
            }
        }    
        return ans;    
    }
};