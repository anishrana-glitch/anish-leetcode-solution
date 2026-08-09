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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
        return res;
        queue<TreeNode*> q;
        bool lefttoright=1;
        q.push(root);
        while(!q.empty()){
            int lvlsize=q.size();
            vector<int> tmp(lvlsize);
            int first=0;
            int last=lvlsize-1;
            for (int i = 0; i < lvlsize; i++) {
            TreeNode* t=q.front();
            q.pop();
            if(lefttoright==1){
                tmp[first]=t->val;
                first++;
            }
            else{
                tmp[last]=t->val;
                last--;
            }
            if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }
            res.push_back(tmp);
            lefttoright = !lefttoright;
        }
        return res;
    }
};