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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
    bool fun(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr and root2==nullptr)
        return true;
        if(root1==nullptr or root2==nullptr)
        return false;
        if(root1->val != root2->val)
        return false;
        bool r1=fun(root1->left,root2->left);
        bool r2=fun(root1->right,root2->right);
        if(r1==true and r2==true)
        return true;
        return false;
    }
};