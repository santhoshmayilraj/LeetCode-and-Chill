class Solution {
public:
    string smallestNumber(string pattern) {
        unordered_map<int,int> hash;
        string ans,temp;
        dfs(hash,temp,ans,pattern,-1,-1);
        return ans;
    }

    void dfs(unordered_map<int,int> &hash,string &temp,string &ans,string &pattern,int count,int prev)
    {
        if(!ans.empty())
        {
            return;
        }
        if(count == pattern.size())
        {
            ans = temp;
            return;
        }
        if(prev == -1)
        {
            for(int i=1;i<10;i++)
            {
                temp.push_back(i+'0');
                hash[i]++;
                dfs(hash,temp,ans,pattern,count+1,i);
                hash[i]--;
                temp.pop_back();
            }
        }      
        else
        {
            if(pattern[count] == 'D')
            {
                for(int i=1;i<temp.back()-'0';i++)
                {
                    if(!hash[i])
                    {
                        temp.push_back(i+'0');
                        hash[i]++;
                        dfs(hash,temp,ans,pattern,count+1,i);
                        hash[i]--;
                        temp.pop_back();
                    }
                }
            }
            else
            {
                for(int i=temp.back()-'0'+1;i<10;i++)
                {
                    if(!hash[i])
                    {
                        temp.push_back(i+'0');
                        hash[i]++;
                        dfs(hash,temp,ans,pattern,count+1,i);
                        hash[i]--;
                        temp.pop_back();
                    }
                }
            }
        }   
        return;       
    }
};