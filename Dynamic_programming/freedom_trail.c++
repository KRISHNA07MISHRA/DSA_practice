class Solution {
public:
    int solve(string &ring, string &key , int prev, int curr,vector<vector<int>>&dp){
        if(curr>=key.length()){
            return 0;
        }
        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }

        int take = INT_MAX;

        for(int i = 0; i<ring.length(); i++){
            if(ring[i] == key[curr]){
                int clock = abs(prev-i);

                int anti = ring.length() - abs(prev - i);

                int val = min( clock, anti);

                take = min(take, val+solve(ring,key,i,curr+1,dp));
            }
        }
        return dp[curr][prev] = take;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        vector<vector<int>> dp(100+1,vector<int>(100+1,-1));

        return solve(ring,key,0,0,dp)+key.length();
    }
};