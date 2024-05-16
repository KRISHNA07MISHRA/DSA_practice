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
    void solve(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        solve(root->left);
        solve(root->right);
        if(root->val == 2){
            int val = root->left->val | root->right->val;
            root->val = val;
        }
        else if(root->val == 3){
            int val = root->left->val & root->right->val;
            root->val = val;
        }

       
    }
    bool evaluateTree(TreeNode* root) {
        solve(root);
        return root->val;
    }
};