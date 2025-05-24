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
    int maxPathSum(TreeNode* root) {
        int diameter = INT_MIN;
        helper(root,diameter);
        return diameter;
    }

    int helper(TreeNode* root,int &diameter)
    {
        if(!root)
        {
            return 0;
        }
        int leftsum = helper(root->left,diameter);
        int rightsum = helper(root->right,diameter);
        // if(diameter == 0)
        // {
        //     diameter = max({leftsum+root->val,rightsum+root->val,leftsum+rightsum+root->val,root->val});
        // }
        diameter = max({leftsum+root->val,rightsum+root->val,leftsum+rightsum+root->val,diameter,root->val});
        return max({leftsum+root->val,rightsum+root->val,root->val});
    }
};