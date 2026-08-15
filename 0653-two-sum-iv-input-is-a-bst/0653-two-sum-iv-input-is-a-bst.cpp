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
    vector<int> tmp;
    bool findTarget(TreeNode* root, int k) {
        fun(root);
        int i=0;
        int j=tmp.size()-1;
        while(i<j){
        int sum = tmp[i]+tmp[j];
        if(sum==k)
        return true;
        if(sum<k)
        i++;
        else if(sum>k)
        j--;
        }
        return false;

    }
    void fun(TreeNode* root){
        if(root==nullptr)
        return;
        fun(root->left);
        tmp.push_back(root->val);
        fun(root->right);
        return;
    }

};