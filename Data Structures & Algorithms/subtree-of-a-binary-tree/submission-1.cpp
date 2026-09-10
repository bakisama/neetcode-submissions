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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     bool isASub = false;
     if(!root && !subRoot) return true;
     if(!root || !subRoot) return false;
     if(root->val == subRoot->val) isASub = isSameTree(root,subRoot);
     if(isASub) return isASub;
     isASub = isSubtree(root->left,subRoot);
     if(isASub) return isASub;
     isASub = isSubtree(root->right,subRoot);
     if(isASub) return isASub;
     return isASub;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q ||p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};
