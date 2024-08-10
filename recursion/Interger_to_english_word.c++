class Solution {
public:
    unordered_map<int,string> belowten = {{1, "One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},
    {7,"Seven"},{8,"Eight"},{9,"Nine"}};
    unordered_map<int,string> belowtwenty = {{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},
    {17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
    unordered_map<int,string> belowhundred = {{1,"Ten"},{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"}
    ,{8,"Eighty"},{9,"Ninety"}};

    string solve(int num){
        if(num<10){ // 9 8 7 6
            return belowten[num];
        }
        if(num<20){ //19 18 17 16
            return belowtwenty[num];
        }
        if(num<100){ //99 98 97 96 95
            return belowhundred[num/10] + (num%10>0 ? " "+ belowten[num%10]:"");
        }
        if(num<1000){//999 998 997 996 900
            return solve(num/100) + " Hundred"+ (num%100 !=0 ? " "+ solve(num%100) : "");
        }
        if(num<1000000){// 99999
            return solve(num/1000) + " Thousand" + (num%1000 >0 ? " "+ solve(num%1000) : "");
        }
        if(num<1000000000){
            return solve(num/1000000) + " Million" + (num%1000000 >0 ? " "+ solve(num%1000000) : "");
        }
       
        return solve(num/1000000000) + " Billion"+ (num%1000000000 >0 ? " "+ solve(num%1000000000) : "");
        
        
    }
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        return solve(num);
    }
};