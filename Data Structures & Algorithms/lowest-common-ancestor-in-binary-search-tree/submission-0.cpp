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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p == root || q == root return root
        // if p < root && root < q return root
        // if p < root && q < root search left subtree
        // if root < q && root < p search right subtree

        if(root->val < q->val && root->val < p->val) return lowestCommonAncestor(root->right, p , q);
        if(root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p , q);
        if((p->val < root->val && root->val < q->val) || (p->val > root->val && root->val > q->val)) return root;
        if((p->val == root->val)||(q->val == root->val))return root;

    }
};
