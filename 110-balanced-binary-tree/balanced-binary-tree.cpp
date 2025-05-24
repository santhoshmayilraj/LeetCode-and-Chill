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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root,ans);
        return ans;
    }

    int helper(TreeNode* root,bool &ans)
    {
        if(!root)
        {
            return 0;
        }
        int leftsum = helper(root->left,ans);
        int rightsum = helper(root->right,ans);
        if(abs(leftsum-rightsum)>1)
        {
            ans = false;
        }
        return max(leftsum,rightsum)+1;
    }
};