class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mporder;
        unordered_map<char,int> mps;
        for(int i = 0; i<order.length(); i++){
            mporder[order[i]]++;
        }
        for(int i = 0; i<s.length(); i++){
            mps[s[i]]++;
        }
        string ans = "";

        for(int i = 0; i<order.length(); i++){
            if(mps.find(order[i]) != mps.end()){
                int count = mps[order[i]];
                while(count>0){
                    ans += order[i];
                    count--;
                }
                
            }
        }
        for(int i = 0; i<s.length(); i++){
            if(mporder.find(s[i]) == mporder.end()){
                ans += s[i];
            }
        }
        return ans;

    }
};