class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto& pair : richer) {
            graph[pair[1]].push_back(pair[0]); // a is richer than b
        }

        vector<int> answer(n, -1); // memoization: answer[i] = index of quietest person richer/equal to i

        for (int i = 0; i < n; i++) {
            dfs(i, graph, quiet, answer);
        }

        return answer;
    }

    int dfs(int person, vector<vector<int>>& graph, vector<int>& quiet, vector<int>& answer) {
        if (answer[person] != -1) return answer[person]; // already computed

        int min_person = person;
        for (int richer_person : graph[person]) {
            int candidate = dfs(richer_person, graph, quiet, answer);
            if (quiet[candidate] < quiet[min_person]) {
                min_person = candidate;
            }
        }

        answer[person] = min_person;
        return min_person;
    }
};
