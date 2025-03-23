class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, int> hash;
        for (auto i : supplies) {
            hash[i]++;
        }

        vector<string> ans;
        unordered_map<string,int> index;
        for(int i=0;i<recipes.size();i++)
        {
            index[recipes[i]] = i;
        }
        vector<int> visited(recipes.size(),0);
        for(int i=0;i<recipes.size();i++)
        {
            if(!visited[i])
            {
                helper(hash,ingredients,index,visited,ans,recipes[i]);
            }
        }
        return ans;
    }

    void helper(unordered_map<string,int>& hash,vector<vector<string>>& ingredients,unordered_map<string,int>& index,vector<int>& visited,vector<string>& ans,string temp)
    {
        int curr = index[temp];
        if(visited[curr])
        {
            return;
        }
        visited[curr] = 1;
        for(string i:ingredients[curr])
        {
            if(hash[i])
            {
                continue;
            }
            else
            {
                helper(hash,ingredients,index,visited,ans,i);
                if(!hash[i])
                {
                    return;
                }
            }
        }
        hash[temp] = 1;
        ans.push_back(temp);
    }
};