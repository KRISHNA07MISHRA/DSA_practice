class Solution {
public:
    int solve(vector<vector<int>>&grid,int row, int col,vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();

        if(row>=n || row<0 || col>=m || col<0){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int take = INT_MAX;
        if(row == n-1){
            take = min(take,grid[row][col]);
            return take;
        }
        
        for( int j = 0; j <m; j++){
            if( j != col){
                take = min(take,grid[row][col] + solve(grid,row+1,j,dp));

                
            }

        }

        return dp[row][col] = take;



    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
       
        vector<vector<int>>dp(201,vector<int>(201,-1));
        for(int i = 0; i<grid[0].size(); i++){
            ans = min(ans,solve(grid,0,i,dp));
        }
        return ans;
    }
};