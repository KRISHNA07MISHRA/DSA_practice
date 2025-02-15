// int solve(vector<int>&height, int level,vector<int>&dp){
    //     
    //     if(level == height.size()-1){
    //         return 0;
            
    //     }
    //     if(dp[level] != -1){
    //         return dp[level];
    //     }
    //     int first = INT_MAX;
    //     int second = INT_MAX;
        
    //     if(level+1<height.size()){
    //         first = abs(height[level+1]-height[level]) + solve(height,level+1,dp);
    //     }
    //     if(level+2<height.size()){
    //         second = abs(height[level+2]-height[level]) + solve(height,level+2,dp);
    //     }
        
        
        
    //     return dp[level] = min(first,second);
    // }
    
    int top_down(vector<int>&height, int level,vector<int>&dp){
        if(level == 0){
            return 0;
        }
        if(dp[level] != -1){
            return dp[level];
        }
        int first = abs(height[level]-height[level-1]) + top_down(height,level-1,dp);
        
        
        int second  = INT_MAX;
        if(level-2>=0){
            second = abs(height[level]-height[level-2]) + top_down(height,level-2,dp);
        }
        
        return dp[level] = min(first,second);
    }
    int minCost(vector<int>& height) {
         int n = height.size();
        //  vector<int> dp(n+1,-1);
        //  return top_down(height,n-1,dp);
        
        
        // vector<int> dp(n,0);
        
        // dp[0] = 0;
        
        // for(int i= 1; i<n; i++){
        //     int first_step = abs(height[i]-height[i-1]) + dp[i-1];
            
        //     int second_step = INT_MAX;
        //     if(i>1){
        //         second_step = abs(height[i]-height[i-2]) + dp[i-2];
        //     }
            
        //     dp[i] = min(first_step,second_step);
        // }
        
        // return dp[n-1];
        
        int prev = 0;
        int prev2 = 0;
        
        for(int i = 1; i<n; i++){
            int first = prev + abs(height[i]-height[i-1]);
            
            int second = INT_MAX;
            if(i>1){
                second = prev2 + abs(height[i]-height[i-2]);
            }
            
            int curr = min(first,second);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;