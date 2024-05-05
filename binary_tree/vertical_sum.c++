class Solution{
  public:
    void solve(Node* root, map<int,int>&mp,int level){
        if(root == NULL){
            return;
        }
        mp[level] += root->data;
        solve(root->left,mp,level-1);
        solve(root->right,mp,level+1);
    }
    vector <int> verticalSum(Node *root) {
        map<int,int> mp;
        
        solve(root,mp,0);
        
        vector<int> ans;
        for(auto temp:mp){
            ans.push_back(temp.second);
        }
        return ans;
    }
};