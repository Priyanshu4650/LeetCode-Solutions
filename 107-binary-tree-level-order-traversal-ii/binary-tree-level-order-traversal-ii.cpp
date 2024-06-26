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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int t = q.size();
            vector<int> temp;

            for(int i=0;i<t;i++) {
                TreeNode *curr = q.front();
                temp.push_back(curr->val);
            
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
                
                q.pop();
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};