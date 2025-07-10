class Solution {
public:
    bool ispalindrome(string curr)
    {
        int l=0;
        int r= curr.size()-1;
        while(l<=r)
        {
            if(curr[l]!=curr[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
        {
            return "";
        }
        string temp = palindrome;
        for(int i=0;i<palindrome.size();i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                break;
            }
        }
        if(ispalindrome(palindrome))
        {
            temp[temp.size()-1] = 'b';
            return temp;
        }
        return palindrome;
    }
};