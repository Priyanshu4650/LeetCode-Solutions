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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        int level=0;
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> curr;
            for(int i=0;i<s;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(level%2) node->val = ans[s-i-1];
                
                if(node->left) 
                {
                    q.push(node->left);
                    curr.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    curr.push_back(node->right->val);
                }
            }
            ans = curr;
            level++;
        }
        return root;
    }
};