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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> hash;
        int ans = helper(root,hash);
        return ans;
    }

    int helper(TreeNode* root,unordered_map<TreeNode*,int> &hash)
    {
        if(hash[root])
        {
            return hash[root];
        }
        int left_max=0,right_max=0;
        int left_near=0,right_near=0;
        if(root->left)
        {
            if(root->left->left)
            {
                left_max += helper(root->left->left,hash);
            }
            if(root->left->right)
            {
                left_max += helper(root->left->right,hash);
            }
            left_near = helper(root->left,hash);
        }
        if(root->right)
        {
            if(root->right)
            {
                if(root->right->left)
                {
                    right_max += helper(root->right->left,hash);
                }
                if(root->right->right)
                {
                    right_max += helper(root->right->right,hash);
                }
                right_near = helper(root->right,hash);
            }
        }
        int max_val = max({left_max+right_max+root->val,left_near+right_near});
        hash[root] = max_val;
        return max_val;
    }
};