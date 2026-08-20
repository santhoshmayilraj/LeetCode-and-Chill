class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<bool>> checkArr;
        for (auto &seat : reservedSeats) {

            int row = seat[0];
            int col = seat[1];

            if (checkArr.find(row) == checkArr.end()) {
                checkArr[row] = vector<bool>(3, true);
            }

            if (col >= 2 && col <= 5) {
                checkArr[row][0] = false;
            }

            if (col >= 4 && col <= 7) {
                checkArr[row][1] = false;
            }

            if (col >= 6 && col <= 9) {
                checkArr[row][2] = false;
            }
        }

        long long answer = 2LL * n;

        for (auto &row : checkArr) {

            bool A = row.second[0];
            bool B = row.second[1];
            bool C = row.second[2];

            if (A && C) {
            }
            else if (A || B || C) {
                answer -= 1;
            }
            else {
                answer -= 2;
            }
        }

        return answer;
    }
};