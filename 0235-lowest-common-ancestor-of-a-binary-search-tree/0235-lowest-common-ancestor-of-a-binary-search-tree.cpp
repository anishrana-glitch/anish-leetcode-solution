/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans= nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root,p,q);
        return ans;
    }
    void fun(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return;
        if (root == p && root == q) {
        ans = root;
        return;
    }
        if (p->val < root->val && q->val < root->val) {
            fun(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) {
            fun(root->right, p, q);
        }
        else {
            ans = root;
            return;
        }
    }
};