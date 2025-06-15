class Solution {
    public:
        string generateTag(string caption) {
            string ans = "#";
            int i = 0;
            while(i<caption.length()){
                if(i == 0){
                    ans += (char)tolower(caption[i]);
                }
               
                else if(caption[i] == ' '){
                    while(caption[i] == ' '){
                        i++;
                    }
                    
                    ans += (char)toupper(caption[i]);
                }
                else{
                    ans += (char)tolower(caption[i]);
                }
                i++;
            }
    
            string result = "";
            int j = 0;
            while(j<ans.length() && j<100){
                if((ans[j]>='a' && ans[j]<='z') || (ans[j]>='A' && ans[j]<='Z') || ans[j] == '#'){
                    result += ans[j];
                }
                j++;
            }
            return result;
            
        }
    };