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
    int maxdepth;
    int leftmostval;
    void dfs(TreeNode* root, int currentdepth){
        if(root == NULL){
            return ;
        }
        if(currentdepth>maxdepth){
            maxdepth = currentdepth;
            leftmostval = root->val;
        }
        dfs(root->left,currentdepth+1);
        dfs(root->right,currentdepth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int val = -1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            val = top->val;
            if(top->right){
                q.push(top->right);

            }
            if(top->left){
                q.push(top->left);
            }
        }
        return val;
    }
};