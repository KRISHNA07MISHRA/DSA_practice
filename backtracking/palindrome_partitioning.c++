class Solution {
public:
    bool check(string s, int start, int end){
       if(start>end){
        return true;
       }
       
       while(start<end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
       }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&temp, string s, int start){
        if(start>=s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = start+1; i<=s.length(); i++){
            if(check(s,start,i-1)){
                temp.push_back(s.substr(start,i-start));

                solve(ans,temp,s,i);
                temp.pop_back();

                //solve(ans,temp,s,i);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,s,0);

        return ans;
    }
};