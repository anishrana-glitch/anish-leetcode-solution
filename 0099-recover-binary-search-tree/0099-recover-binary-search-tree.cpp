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
TreeNode* prev = nullptr;
int galat=0;
TreeNode* g1f=nullptr;
TreeNode* g1s=nullptr;
TreeNode* g2f=nullptr;
TreeNode* g2s=nullptr;
void fun(TreeNode* root){
    if(root==nullptr)
    return;
    fun(root->left);
    if(prev==nullptr){
    prev=root;
}
    else{
        if(root->val < prev->val){
            if(galat==0){
            g1f=prev;
            g1s=root;
        }
        else{
            g2f=prev;
            g2s=root;
        }
        galat++;
    }
    prev=root;
}
fun(root->right);
}
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat==1)
        swap(g1f->val,g1s->val);
        else
        swap(g1f->val,g2s->val);
        return;
    }
};