int top_down(vector<int>&arr, int level, int k,vector<int>&dp){
    if(level == 0){
        return 0;
    }
    
    if(dp[level] != -1){
        return dp[level];
    }
    int mini = INT_MAX;
    for(int i = level-1; i>= max(0,level-k); i--){
        mini = min(mini,abs(arr[i]-arr[level]) + top_down(arr,i,k,dp));
    }
    
    return dp[level] = mini;
}
int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    // vector<int> dp(n+1,-1);
    // return top_down(arr,n-1,k,dp);
    
    vector<int> dp(n,0);
    dp[0] = 0;
    
    for(int i = 1; i<n; i++){
        int mini = INT_MAX;
        for(int j = i-1; j>=max(0,i-k); j--){
            mini = min(mini,dp[j] + abs(arr[j]-arr[i]));
        }
        
        dp[i] = mini;
    }
    return dp[n-1];
}