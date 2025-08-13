class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> hash;
        for(int i:arr)
        {
            hash[(k+(i%k))%k]++;
        }
        for(int i:arr)
        {
            if((k+(i%k))%k == 0)
            {
                if(hash[(k+(i%k))%k]%2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if(hash[k-((k+(i%k))%k)])
                {
                    hash[k-((k+(i%k))%k)]--;
                    hash[(k+(i%k))%k]--;
                }
                else if(hash[(k+(i%k))%k] == 0)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;        
    }
};