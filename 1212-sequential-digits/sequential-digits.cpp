class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_count = log10(low);
        int high_count = log10(high);
        low_count++;
        high_count++;
        vector<int> ans;
        string digits = "123456789";
        for(int i=low_count;i<high_count+1;i++){
            for(int j=0;j<=9-i;j++){
                int curr_str = stoi(digits.substr(j,i));
                if(low <= curr_str && curr_str <= high){
                    ans.push_back(curr_str);
                }

            }
        }
        return ans;
    }
};