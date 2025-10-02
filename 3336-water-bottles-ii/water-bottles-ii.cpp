class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int empty_bottles = 0;
        while(numBottles)
        {
            ans += numBottles;
            empty_bottles += numBottles;
            numBottles = 0;
            while(empty_bottles >= numExchange)
            {
                numBottles++;
                empty_bottles -= numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};