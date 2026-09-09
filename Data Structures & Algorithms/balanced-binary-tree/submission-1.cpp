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
    int height(TreeNode * root) {
        if(root == NULL) return 0;
        int lefth = height(root->left);
        int righth = height(root->right);
        return 1+max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if(1<abs(leftH-rightH))return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    
};
