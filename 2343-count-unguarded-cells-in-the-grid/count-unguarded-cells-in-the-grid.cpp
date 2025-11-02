#include <vector>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = Unguarded
        // -1 = Blocker (Wall or Guard)
        // 1 = Guarded
        vector<vector<int>> temp(m, vector<int>(n, 0));

        // Mark all walls as blockers
        for (int i = 0; i < walls.size(); i++) {
            temp[walls[i][0]][walls[i][1]] = -1;
        }
        
        // Mark all guards as blockers
        for (int i = 0; i < guards.size(); i++) {
            temp[guards[i][0]][guards[i][1]] = -1;
        }

        // Paint guarded cells
        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];

            // Move Right
            for (int j = y + 1; j < n; j++) {
                if (temp[x][j] == -1) { // Stop for blockers
                    break;
                }
                if (temp[x][j] == 0) { // Only paint empty cells
                    temp[x][j] = 1;
                }
                // If temp[x][j] == 1, we continue
            }
            
            // Move Left
            for (int j = y - 1; j >= 0; j--) {
                if (temp[x][j] == -1) {
                    break;
                }
                if (temp[x][j] == 0) {
                    temp[x][j] = 1;
                }
            }

            // Move Down
            for (int j = x + 1; j < m; j++) {
                if (temp[j][y] == -1) {
                    break;
                }
                if (temp[j][y] == 0) {
                    temp[j][y] = 1;
                }
            }

            // Move Up
            for (int j = x - 1; j >= 0; j--) {
                if (temp[j][y] == -1) {
                    break;
                }
                if (temp[j][y] == 0) {
                    temp[j][y] = 1;
                }
            }
        }

        // Count the remaining unguarded (0) cells
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};