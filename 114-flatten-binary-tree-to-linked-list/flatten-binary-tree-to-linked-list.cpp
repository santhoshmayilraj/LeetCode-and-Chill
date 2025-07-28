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
    void flatten(TreeNode* root) {
        stack<TreeNode*> temp;
        if(root)
        {
            temp.push(root);
            vector<int> temp1;
            while(!temp.empty())
            {
                TreeNode* temp2;
                temp2 = temp.top();
                temp.pop();
                if(temp2->right)
                {
                    temp.push(temp2->right);
                }
                if(temp2->left)
                {
                    temp.push(temp2->left);
                }
                temp1.push_back(temp2->val);
            }

            int i=0;
            TreeNode* prev = nullptr;
            while(i<temp1.size()-1)
            {
                TreeNode* next = new TreeNode();
                next->left = nullptr;
                next->val = temp1[temp1.size()-i-1];
                next->right = prev;
                prev = next;
                i++;
            }
            root->left = nullptr;
            root->right = prev;
        }
    }
};