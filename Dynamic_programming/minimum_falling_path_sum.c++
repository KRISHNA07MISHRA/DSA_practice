class Solution {
public:
    int solve(vector<vector<int>>&matrix, int row, int col,vector<vector<int>>&dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(row<0 || row>=n || col<0 || col>=m){
            return 0;
        }
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }
        int op1 = INT_MAX;
    
        if(row<n && col-1>=0)
            op1 = matrix[row][col] + solve(matrix,row+1,col-1,dp);
        int op2 = INT_MAX;
        if(row<n && col>=0 && col<m )
            op2 = matrix[row][col] + solve(matrix,row+1,col,dp);
        int op3 = INT_MAX;
        if(row<n && col+1<m)
            op3 = matrix[row][col] + solve(matrix,row+1,col+1,dp);

        return dp[row][col] = min(op1,min(op2,op3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(1000,vector<int>(1000,INT_MAX));
        for(int i = 0; i<matrix[0].size(); i++){
            ans = min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};