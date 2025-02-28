class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> hash;
        for(auto i:nums)
        {
            hash[i]++;
        }
        string ans = "";
        string temp = "";
        helper(hash,ans,nums.size(),temp);
        return ans;        
    }

    void helper(unordered_map<string,int> &hash,string &ans,int n,string &temp)
    {
        if(n==temp.size())
        {
            if(!hash[temp])
            {
                ans = temp;
            }
            return;
        }
        if(temp.size()>n)
        {
            return;
        }
        temp.push_back('0');
        helper(hash,ans,n,temp);
        temp.pop_back();
        temp.push_back('1');
        helper(hash,ans,n,temp);
        temp.pop_back();
        return;
    }
};