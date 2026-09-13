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
int nodes = 0;
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        checkGood(root, root->val);
        return nodes;
        
    }
    void checkGood(TreeNode* root, int maxVal){
        if(!root) return;

        if(root->val>=maxVal){
            nodes++;
        }
        maxVal = max(maxVal, root->val);

        checkGood(root->left, maxVal);
        checkGood(root->right, maxVal);

    }
};
