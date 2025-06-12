#include <climits>
#include <queue>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int sz = q.size();
            long long first_val = q.front().second;
            long long curr_min = LLONG_MAX, curr_max = 0;
            
            for (int i = 0; i < sz; ++i) {
                auto curr = q.front(); q.pop();
                TreeNode* curr_node = curr.first;
                long long curr_value = curr.second - first_val;
                
                curr_min = min(curr_min, curr_value);
                curr_max = max(curr_max, curr_value);
                
                if (curr_node->left)
                    q.push({curr_node->left, curr_value * 2});
                if (curr_node->right)
                    q.push({curr_node->right, curr_value * 2 + 1});
            }
            
            ans = max(ans, curr_max - curr_min + 1);
        }
        
        return static_cast<int>(ans);
    }
};
