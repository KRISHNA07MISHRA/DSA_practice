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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(level%2 == 0){ // even
                if(temp[0]%2 == 0){
                    return false;
                }
                for(int i = 1; i<temp.size(); i++){
                    if(temp[i]%2 ==0 ||temp[i]<=temp[i-1] ){
                        return false;
                    }
                }
                
            }
            else{
                if(temp[0]%2 != 0){
                    return false;
                }
                for(int i = 1; i<temp.size(); i++){
                    if(temp[i]%2 != 0 || temp[i]>=temp[i-1]){
                        return false;
                    }
                }
                
            }
            level++;
        }
        return true;
    }
};