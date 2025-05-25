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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> temp;
        if(!root)
        {
            return temp;
        }
        int min_v(0),max_v(0);
        helper(root,temp,0,0,min_v,max_v); 
        vector<vector<int>> ans(max_v-min_v+1);
        sort(temp.begin(),temp.end());
        for(vector<int> i:temp)
        {
            ans[i[0]-min_v].push_back(i[2]);
        }
        return ans;
    }

    void helper(TreeNode* root,vector<vector<int>> &temp,int i,int j,int &min_v,int &max_v)
    {
        min_v = min(min_v,i);
        max_v = max(max_v,i);
        temp.push_back({i,j,root->val});
        if(root->left)
        {
            helper(root->left,temp,i-1,j+1,min_v,max_v);
        }
        if(root->right)
        {
            helper(root->right,temp,i+1,j+1,min_v,max_v);
        }
        return;
    }
};