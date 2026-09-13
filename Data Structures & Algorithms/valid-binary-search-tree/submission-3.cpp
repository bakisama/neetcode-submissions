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
    bool valid = true;
    bool isValidBST(TreeNode* root) {
        valid = true;
        int left = INT_MIN;
        int right = INT_MAX;
        validateBST(root, left, right);
        return valid;
    }
    void validateBST(TreeNode* root, int left, int right) {
        if (!root) return;
        if (!(left < root->val && root->val < right)) {
            valid = false;
            return;
        }
        validateBST(root->left, left, root->val);
        validateBST(root->right, root->val, right);
    }
};
