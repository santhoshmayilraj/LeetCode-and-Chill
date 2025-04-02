class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int ans = 0;
        if(startGene == endGene)
        {
            return ans;
        }
        unordered_map<string,int> visited;
        for(string i:bank)
        {
            visited[i] = 1;
        }
        queue<string> temp;
        temp.push(startGene);
        vector<char> charecters = {'A','G','T','C'};
        while(!temp.empty())
        {
            ans++;
            int sz = temp.size();
            for(int k=0;k<sz;k++)
            {
                string curr = temp.front();
                temp.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string curr1 = curr;
                    for(char j:charecters)
                    {
                        curr1[i] = j;
                        if(visited[curr1] == 1)
                        {
                            if(curr1 == endGene)
                            {
                                return ans;
                            }
                            temp.push(curr1);
                            visited[curr1] = 2;
                        }
                    }
                }
            }
        }   
        return -1;     
    }
};