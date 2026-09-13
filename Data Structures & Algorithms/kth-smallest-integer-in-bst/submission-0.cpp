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
vector<int> tree;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        treeToVec(root);
        return tree[k-1];
    }
    void treeToVec(TreeNode* root){
        if(!root) return;
        if(root->left!=NULL)treeToVec(root->left);
        tree.push_back(root->val);
        if(root->right!=NULL)treeToVec(root->right);
    }
};
