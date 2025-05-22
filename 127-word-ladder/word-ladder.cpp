class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> hash;
        if(beginWord == endWord)
        {
            return 0;
        }
        for(string i:wordList)
        {
            hash[i] = 1;
        }
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        vector<char> alpha;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            alpha.push_back(ch);
        }
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string curr1 = curr;
                    for(char ch:alpha)
                    {
                        curr1[i] = ch;
                        if(hash[curr1] == 1)
                        {
                            if(curr1 == endWord)
                            {
                                return ans;
                            }
                            hash[curr1] = 2;
                            q.push(curr1);
                        }
                    }
                }
            }
        }
        return 0;
    }
};