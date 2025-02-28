class Solution {
public:
    string getHappyString(int n, int k) {
        int count = 0;
        string temp = "";
        string ans="";
        char prev = 'd';
        vector<char> dict = {'a','b','c'};
        dfs(temp,n,k,count,ans,prev,dict); 
        return ans;       
    }

    void dfs(string &temp,int n,int k,int &count,string &ans,char prev,vector<char> &dict)
    {
        // if(temp.size()>n and count<k)
        // {
        //     ans = "";
        //     return;
        // }
        if(temp.size() == n and count == k)
        {
            ans = temp;
            return;
        }
        if(temp.size() < n)
        {
            for(char i:dict)
            {
                if(prev != i)
                {
                    char temp2 = prev;
                    temp.push_back(i);
                    prev = i;
                    if(temp.size() == n)
                    {
                        count++;
                    }
                    dfs(temp,n,k,count,ans,prev,dict);
                    temp.pop_back();
                    prev = temp2;
                }
            }
        }
        return;       
    }

};