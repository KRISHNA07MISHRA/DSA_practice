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
   // vector<string> ans;
    string temp = "";
    void solve(TreeNode* root,string& ans){
        if(root == NULL){
            return;
        }
        temp += root->val+'a';
        if(root->left == NULL && root->right == NULL){
            reverse(temp.begin(),temp.end());
            if(ans == "" || ans>temp){
                ans = temp;
            }
           
           reverse(temp.begin(),temp.end());


        }
        
        solve(root->left,ans);
        solve(root->right,ans);
        temp.pop_back();
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "" ;

        solve(root,ans);
        return ans;


    }
};