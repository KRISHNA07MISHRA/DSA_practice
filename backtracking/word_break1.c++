class Solution {
public:
    unordered_map<string,int> mp;
    bool solve(string s, int index){
        if(index>=s.length()){
            return true;
        }

        if(mp.find(s) != mp.end()){
            return true;
        }

        for(int len = 1; len<=s.length(); len++){
            if(mp.find(s.substr(index,len)) != mp.end() && solve(s,index+len)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }

        return solve(s,0);
    }
};