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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool le = isBalanced(root->left);
        bool ri = isBalanced(root->right);
        int left = height(root->left);
        int right = height(root->right);
        if(!le || !ri) return false;
        if(1<(abs(left-right))) return false;
        return true;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1+max(leftH,rightH);

    }
    // int leftH(TreeNode* root) {
    //     if (root == NULL) return 0;

    //     return 1 + leftH(root->left);
    // }
    // int rightH(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     return 1 + rightH(root->right);
    // }
};
