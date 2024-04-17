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
    TreeNode* solve(TreeNode* root, int val, int depth, int curr){
        if(root == NULL){
            return root;
        }
        if (curr == depth - 1) {
        TreeNode* newnode = new TreeNode(val);
        newnode->left = root->left;
        root->left = newnode;

        TreeNode* newnode2 = new TreeNode(val);
        newnode2->right = root->right;
        root->right = newnode2;

        return root;
    }
        if(root->left){
            solve(root->left,val,depth,curr+1);
        }
        if(root->right)
            solve(root->right,val,depth,curr+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        return solve(root,val,depth,1);
    }
};