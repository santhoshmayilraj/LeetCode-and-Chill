/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root == p or root == q)
        {
            return root;
        }
        TreeNode* l;
        TreeNode* r;
        l = lowestCommonAncestor(root->left,p,q);
        r = lowestCommonAncestor(root->right,p,q);
        if(!l and !r)
        {
            return nullptr;
        }
        if(!l)
        {     
            return r;
        }
        else if(!r)
        {
            return l;
        }

        return root;

    }
};