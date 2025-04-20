class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> hash;
        for(int i:answers)
        {
            hash[i]++;
        }
        int ans(0);
        for(auto i:hash)
        {
            int temp = (i.second)/(i.first+1);
            ans += temp*(i.first+1);
            if(i.second%(i.first+1))
            {
                ans += i.first+1;
            }
        }
        return ans;        
    }
};