class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();

                for (int j = 0; j < curr.size(); ++j) {
                    char original = curr[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == original) continue;
                        curr[j] = ch;

                        if (curr == endWord) {
                            return steps + 1;
                        }

                        if (wordSet.find(curr) != wordSet.end()) {
                            q.push(curr);
                            wordSet.erase(curr);
                        }
                    }
                    curr[j] = original;  
                }
            }
            steps++;
        }

        return 0;
    }
};