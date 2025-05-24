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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == nullptr ) or (q ==nullptr))
        {
            if((p==nullptr)and(q==nullptr))
            {
                return true;
            }
            return false;
        }

        if(p->val != q->val)
        {
            return false;
        }

        bool temp1 = isSameTree(p->left,q->left);
        bool temp2 = isSameTree(p->right,q->right);

        return temp1 and temp2;        
    }
};