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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<TreeNode*,vector<long long>> hash;
        if(!root)
        {
            return count;
        }
        helper(root,count,targetSum,hash);
        return count;
    }

    void helper(TreeNode* root,int &count,int targetSum,unordered_map<TreeNode*,vector<long long>> &hash)
    {
        if(!root->left and !root->right)
        {
            if(root->val == targetSum)
            {
                count++;
            }
            hash[root].push_back(root->val+0ll);
            return;
        }
        if(root->left)
        {
            helper(root->left,count,targetSum,hash);
            for(long long i:hash[root->left])
            {
                if(root->val+i+0ll == targetSum)
                {
                    count++;
                }
                hash[root].push_back(root->val+i+0ll);
            }
        }
        if(root->right)
        {
            helper(root->right,count,targetSum,hash);
            for(long long i:hash[root->right])
            {
                if(root->val+i+0ll == targetSum)
                {
                    count++;
                }
                hash[root].push_back(root->val+i+0ll);
            }
        }
        if(root->val==targetSum)
        {
            count++;
        }       
        hash[root].push_back(root->val+0ll);
        return;      
         
    }
};