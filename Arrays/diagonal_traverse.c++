class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[i].size(); j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flag = true;

        for(auto temp:mp){
            if(flag){
                reverse(temp.second.begin(),temp.second.end());
                for(auto it:temp.second){
                    ans.push_back(it);
                }
                flag = false;
            }
            else{
                for(auto it:temp.second){
                    ans.push_back(it);

                }
                flag = true;
            }
        }
        return ans;
    }
};