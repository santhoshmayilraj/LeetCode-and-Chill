class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        vector<string> temp(numRows,"");
        bool flag = true;
        int curr_row = 0;
        for(int i=0;i<s.size();i++)
        {
            if(flag == true)
            {
                temp[curr_row] += s[i];
                curr_row++;
            }
            else
            {
                temp[curr_row] += s[i];
                curr_row--;
            }
            if(curr_row == numRows)
            {
                flag = false;
                curr_row-=2;
            }
            if(curr_row == -1)
            {
                flag = true;
                curr_row+=2;
            }
        }
        string ans = "";
        for(string curr:temp)
        {
            ans += curr;
        }
        return ans;
        
    }
};