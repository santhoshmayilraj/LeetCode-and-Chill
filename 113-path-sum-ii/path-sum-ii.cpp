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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        vector<int> curr;
        helper(root,targetSum,0,curr,ans);
        return ans;
    }

    void helper(TreeNode* root,int targetSum,int curr_sum,vector<int> &curr,vector<vector<int>> &ans)
    {
        curr_sum += root->val;
        curr.push_back(root->val);
        if(!root->left and !root->right)
        {
            if(curr_sum == targetSum)
            {
                ans.push_back(curr);
            }
            curr.pop_back();
            return;
        }

        if(root->left)
        {
            helper(root->left,targetSum,curr_sum,curr,ans);
        }
        if(root->right)
        {
            helper(root->right,targetSum,curr_sum,curr,ans);
        }
        curr.pop_back();
        return;
    }
};