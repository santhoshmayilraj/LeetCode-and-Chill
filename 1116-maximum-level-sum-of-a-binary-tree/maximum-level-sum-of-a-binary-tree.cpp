/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        long maximum = LONG_MIN;
        int ans(0);
        queue<TreeNode*> q;
        q.push(root);
        int level(0);
        while(!q.empty())
        {
            int temp = q.size();
            long level_sum(0);
            for(int i=0;i<temp;i++)
            {
                TreeNode* curr = q.front();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
                level_sum += curr->val;
                q.pop();
            }
            level++;
            if(level_sum>maximum)
            {
                ans = level;
                maximum = level_sum;
            }
        }
        return ans;        
    }
};