class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int ans = -1;
        while(i<j)
        {
            ans = max(ans,(j-i)*min(height[i],height[j]));
            if(height[i] < height[j])
            {
                i++;
            }
            else if(height[j]<height[i])
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }        
        return ans;
    }
};