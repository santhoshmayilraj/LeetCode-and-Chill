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
        unordered_map<long,int> hash;
        hash[0] = 1;
        helper(root,targetSum,hash,count,0);
        return count;
    }

    void helper(TreeNode* root,int targetSum,unordered_map<long,int> &hash,int &count,long curr_sum)
    {
        if(!root)
        {
            return;
        }
        curr_sum += root->val + 0l;
        if(hash[curr_sum-targetSum])
        {
            count += hash[curr_sum-targetSum];
        }
        hash[curr_sum]++;
        if(root->left)
        {
            helper(root->left,targetSum,hash,count,curr_sum);
        }                
        if(root->right)
        {
            helper(root->right,targetSum,hash,count,curr_sum);
        }
        hash[curr_sum]--;
    }
};