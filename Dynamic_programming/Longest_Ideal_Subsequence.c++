class Solution {
public:
    int dp[10000][27];
    int solve(string& s, int k, int prevchar, int curr){
        if(curr<0){
            return 0;
        }
        if(dp[curr][prevchar] != -1){
            return dp[curr][prevchar];
        }
        int currindex = s[curr];
        int  take = 0;

        if(prevchar == 26 || abs(currindex-prevchar)<=k){
            take = 1+ solve(s,k,currindex,curr-1);
        }
        int nottake = solve(s,k,prevchar,curr-1);

        return dp[curr][prevchar] =  max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        int n = s.length()-1;
        memset(dp,-1,sizeof(dp));
        return solve(s,k,26,n);
    }
};