class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(int i = 0; i<s.length(); i++){
            if(!st.empty() && abs(s[i]-st.top()) == 32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }

        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};