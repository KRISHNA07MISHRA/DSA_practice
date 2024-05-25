class Solution {
public:
    unordered_map<string,int> mp;
    void solve(vector<string>&ans,string& s, string temp,int index){
        if(index>=s.length()){
            ans.push_back(temp);
            return;
        }

        for(int j = index; j<s.length(); j++){
            string val = s.substr(index,j-index+1);
            if(mp.find(val) != mp.end()){
                string prev = temp;
                if(!temp.empty()){
                    temp += " ";
                }
                temp += val;
                solve(ans,s,temp,j+1);
                
                temp = prev;

            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }

        vector<string> ans;
        solve(ans,s,"",0);
        return ans;
    }
};