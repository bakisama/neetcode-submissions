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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> level;
            for(int i = 0;i<len;i++){
                TreeNode* c = q.front();
                q.pop();
                if(c->left!=NULL) q.push(c->left);
                if(c->right!=NULL) q.push(c->right);
                level.push_back(c->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};