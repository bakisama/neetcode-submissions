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
        // deque?
        // level-wise traversal and pop the end at each level?
        /*
        1)
        */
        vector<int> ans;
        if(!root) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int len = dq.size();
            ans.push_back(dq.back()->val);
            for(int i = 0; i<len;i++){
                TreeNode* temp = dq.front();
                dq.pop_front();
                if(temp->left!=NULL)dq.push_back(temp->left);
                if(temp->right!=NULL)dq.push_back(temp->right);
            }
            
        }
        return ans;
        
    }
};
