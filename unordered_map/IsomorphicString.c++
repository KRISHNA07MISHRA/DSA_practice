class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mp1;

        for(int i = 0; i<s.length(); i++){

            if(mp.find(s[i]) == mp.end() && mp1.find(t[i]) == mp1.end()){
                mp[s[i]] = t[i];
                mp1[t[i]] = s[i];
                
            }
            
            else{
                if(mp[s[i]] != t[i]){
                    return false;
                }
                if(mp1[t[i]] != s[i]){
                    return false;
                }
            }
        }

        
        return true;
    }
};