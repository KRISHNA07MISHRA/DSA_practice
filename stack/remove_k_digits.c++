class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i = 0; i<num.length(); i++){
            while(st.size()>0 && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            if(st.size()>0 || num[i]  != '0'){
                st.push(num[i]);
            }
        }
        while(k>0 && st.size()>0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans == ""){
            return "0";
        }
        return ans;
    }
};