class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a != 0 || b !=  0 || c != 0){
            int last1 = a&1;
            int last2 = b&1;
            int last3 = c&1;

            if(last3 == 1){
                if(last1 == 0 && last2 == 0){
                    count++;
                }
            }
            else{
                if(last1 == 1){
                    count++;
                }
                if(last2 == 1){
                    count++;
                }
            }

            a >>=1;
            b>>=1;
            c>>=1;
        }
        return count;
    }
};