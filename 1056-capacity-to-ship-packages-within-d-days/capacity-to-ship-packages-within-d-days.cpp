#include <vector>
#include <numeric>   // For std::accumulate
#include <algorithm> // For std::max_element

using namespace std;

class Solution {
public:
    // Helper function to check if a 'mid' capacity is possible
    bool ispossible(vector<int>& weights, int days, int mid)
    {
        // Error 1: Start day count at 1
        int count = 1;
        int curr_sum = 0;

        for (int r = 0; r < weights.size(); r++)
        {
            // This check is good
            if(weights[r] > mid)
            {
                return false;
            }

            // Error 2: Fix the summing logic
            if(curr_sum + weights[r] > mid)
            {
                // Start a new day
                count++;
                curr_sum = weights[r];
            }
            else
            {
                // Add to the current day
                curr_sum += weights[r];
            }
        }
        
        // Final check
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        // Error 3: Lower bound 'l' must be the largest single item
        int max_elem = *max_element(weights.begin(), weights.end());
        int l = max_elem;

        // Error 4: Upper bound 'r' must be the total sum
        int r = 0;
        for (int w : weights) {
            r += w;
        }

        while(l <= r)
        {
            int mid = l + (r - l) / 2; // (Safer way to calculate mid)
            if(ispossible(weights, days, mid))
            {
                // This capacity 'mid' works, try to find a smaller one
                r = mid - 1;
            }
            else
            {
                // This capacity 'mid' is too small
                l = mid + 1;
            }
        }
        
        // Error 5: Return 'l', which is the first valid capacity
        return l;
    }
};