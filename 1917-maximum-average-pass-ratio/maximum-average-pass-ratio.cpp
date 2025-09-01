class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;
        int temp_div = classes.size();
        for (vector<int> i : classes) {
            double x = i[0];
            double y = i[1];
            double curr_perc = (double)x / y;
            double next_perc = (double)(x+1) / (y+1);
            double change = next_perc - curr_perc;
            pq.push({change, x, y});
        }

        for (int i = 0; i < extraStudents; i++) {
            vector<double> curr = pq.top();
            pq.pop();
            double curr_prec = (curr[1] + 1) / (curr[2] + 1);
            double next_perc = (curr[1] + 2) / (curr[2] + 2);
            double change = next_perc - curr_prec;
            pq.push({change, curr[1] + 1, curr[2] + 1});
        }

        double total_avg = 0;
        while (!pq.empty()) {
            vector<double> curr = pq.top();
            pq.pop();
            total_avg += curr[1] / curr[2];
        }
        return total_avg / temp_div;
    }
};
