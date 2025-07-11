class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> hash;
        for(int i:tasks)
        {
            hash[i]++;
        }

        int ans = 0;
        for(auto i:hash)
        {
            if(i.second == 1)
            {
                return -1;
            }
            ans += i.second/3;
            if(i.second%3)
            {
                ans++;
            }
        }
        return ans;
    }
};