class Solution {
public:
    int minimumLength(string s) {
       int i = 0;
       int j = s.length()-1;
       while(i<=j){
           if(s[i] == s[j] && j-i+1 != 1){
               
                while( i+1<s.length()&& s[i] == s[i+1]){
                    i++;
                }
                while( j-1>0 && s[j] == s[j-1]){
                    j--;
                }
                i++;
                j--;
           }

           else{
               for(int k = i; k<=j; k++){
                   cout<<s[k]<<endl;
               }
               return j-i+1;
           }
       } 
       return 0;
    }
};