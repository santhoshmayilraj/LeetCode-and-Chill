class Solution {
public:
    bool isvowel(char curr)
    {
        if(curr == 'a' or curr == 'e' or curr == 'i' or curr == 'u' or curr == 'A' or curr == 'E' or curr == 'I' or curr == 'U' or curr == 'o' or curr == 'O')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> index;
        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                vowels.push_back(s[i]);
                index.push_back(i);
            }
        }
        sort(vowels.begin(),vowels.end());
        for(int i=0;i<index.size();i++)
        {
            s[index[i]] = vowels[i];
        }
        return s;
    }
};