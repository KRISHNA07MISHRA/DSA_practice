class Solution {
public:
    int n ;
    int m;
    vector<vector<unordered_map<int,int>>> dp;
    int solve(vector<int>& nums, vector<int>&andValues,int i, int j, int value){
        if(i>=n){
            if(j>=m){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        else if(j>=m){
            return 1e9;
        }
        if(dp[i][j].find(value) != dp[i][j].end()){
            return dp[i][j][value];
        }

        int take = 1e9;
        if((value&nums[i] )== andValues[j]){
            take = nums[i] + solve(nums,andValues,i+1,j+1,((1<<17)-1));
        }
        int nottake = solve(nums,andValues,i+1,j,(value&nums[i]));

        return dp[i][j][value] = min(take,nottake);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        m = andValues.size();
        dp.resize(n+1,vector<unordered_map<int,int>>(11));

        int result =  solve(nums,andValues,0,0,((1<<17)-1));
        return result >= 1e9 ? -1 : result;
    }
};