class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // int len = s.length();
        // string ans = string(len,'0');
        
        // int i = 0;
        // for(auto &ch:s){
        //     if(ch == '1'){
        //         if(ans[len-1] == '1'){
        //             ans[i] = '1';
        //             i++;
        //         }
        //         else{
        //             ans[len-1] = '1';
        //         }
        //     }
        // }
        // return ans;

        int n = s.length();
        string ans = string(n,'0');
        int count = 0;
        for(char ch = 0; ch<n; ch++){
            if(s[ch] == '1'){
                count++;
            }

        }
        int j = 0;

        while(count>1){
            ans[j] = '1';
            j++;
            count--;
        }
        ans[n-1] = '1';

        return ans;
    }
};