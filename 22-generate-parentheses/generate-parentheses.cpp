class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open(0),close(0);
        string temp = "";
        helper(ans,temp,n,open,close);
        return ans;        
    }
    void helper(vector<string> &ans,string &temp,int n,int open,int close)
    {
        if(open+close == 2*n)
        {
            ans.push_back(temp);
            return;
        }

        if(open<n)
        {
            temp.push_back('(');
            helper(ans,temp,n,open+1,close);
            temp.pop_back();
        }
        if(close<open)
        {
            temp.push_back(')');
            helper(ans,temp,n,open,close+1);
            temp.pop_back();
        }
        return;
    }
};