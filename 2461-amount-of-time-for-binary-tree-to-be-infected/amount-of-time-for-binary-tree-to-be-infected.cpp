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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        TreeNode* start_val = find_parents(root,parents,start);  
        queue<TreeNode*> q;
        q.push(start_val);
        int level = 0;
        unordered_map<TreeNode*,bool> visited;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                visited[curr] = true;
                if(curr->left and !visited[curr->left])
                {
                    q.push(curr->left);
                }
                if(curr->right and !visited[curr->right])
                {
                    q.push(curr->right);
                }
                if(parents[curr] and !visited[parents[curr]])
                {
                    q.push(parents[curr]);
                }
            }
            level++;
        }
        return level-1;
    }

    TreeNode* find_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parents,int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* start_val;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            if(curr->val == start)
            {
                start_val = curr;
            }
            q.pop();
            if(curr->left)
            {
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return start_val;
    }

};