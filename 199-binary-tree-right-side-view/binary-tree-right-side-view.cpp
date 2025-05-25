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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
        {
            return ans;
        }

        queue<TreeNode*> temp;
        temp.push(root);
        temp.push(nullptr);
        ans.push_back(root->val);
        while(!temp.empty())
        {
            while(temp.front())
            {
                TreeNode* temp1 = temp.front();
                temp.pop();
                if(temp1->right)
                {
                    temp.push(temp1->right);
                }
                if(temp1->left)
                {
                    temp.push(temp1->left);
                }
            }

            if(temp.front() == nullptr)
            {
                temp.pop();
                if(!temp.empty())
                {
                    TreeNode* temp2;
                    temp2 = temp.front();
                    ans.push_back(temp2->val);
                    temp.push(nullptr);
                }
            }
        }
        return ans;        
    }
};