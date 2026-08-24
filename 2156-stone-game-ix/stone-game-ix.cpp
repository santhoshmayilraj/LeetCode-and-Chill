class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int x : stones) {
            if (x % 3 == 0) {
                count0++;
            }
            else if (x % 3 == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        if (count0 % 2 == 0) {
            return count1 > 0 && count2 > 0;
        }

        return abs(count1 - count2) > 2;
    }
};