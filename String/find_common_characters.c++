class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int>  mp;
        string ch = words[0];
        for(auto c:ch){
            mp[c]++;
        }

        for(int i = 1; i<words.size(); i++){
            unordered_map<char,int> mp1;
            string ch = words[i];
            for(auto c:ch){
                mp1[c]++;
            }
            vector<char> todelete;
            for(auto temp:mp){
                char st = temp.first;
                int freq = temp.second;

                if(mp1.find(st) == mp1.end()){
                    todelete.push_back(st);
                }
                else{
                    mp[st] = min(freq,mp1[st]);
                }
            }
            for(auto k:todelete){
                mp.erase(k);
            }
        }
        vector<string> ans;
        for(auto kr:mp){
            char ch = kr.first;
            int freq = kr.second;
            while(freq>0){
                ans.push_back(string(1,ch));
                freq--;
            }
        }
        return ans;
    }
};