class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int countopen = 0;
        int countclose = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                countopen++;
                st.push(s[i]);
            }
            else if(s[i] == ')' ){
                if(countopen>countclose){
                    countclose++;
                    st.push(s[i]);
                
                }
               
            }
            else{
                st.push(s[i]);
            }
        }


        string ans = "";
        while(!st.empty()){
            if(st.top() == '(' && countopen != countclose){
                st.pop();
                countopen--;
            }
            else{
                ans += st.top();
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};