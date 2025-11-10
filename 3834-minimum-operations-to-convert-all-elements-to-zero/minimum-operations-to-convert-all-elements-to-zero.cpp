class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stck;
        int count = 0;
        for(int i:nums)
        {
            while(!stck.empty() and stck.top() > i)
            {
                stck.pop();
                count++;
            }
            if(stck.empty() or stck.top() < i)
            {
                if(stck.empty() and i==0)
                {
                    continue;
                }
                stck.push(i);
                continue;
            }
            else if(stck.top()==i)
            {
                continue;
            }            
        }
        count += stck.size();
        return count;
    }
};