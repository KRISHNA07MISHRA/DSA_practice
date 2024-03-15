class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int mul = 1;
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] != 0){
        //         mul *= nums[i];
        //     }
        // }
        // vector<int> ans(nums.size(),0);
        // unordered_map<int,int> mp;
        // for(int i= 0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // if(mp[0]>1){
        //     return ans;
        // }
        // else if(mp[0] == 1){
        //     for(int i = 0; i<ans.size(); i++){
        //         if(nums[i] == 0){
        //             ans[i] = mul;
        //         }
        //         else{
        //             ans[i] = 0;
        //         }
        //     }
        // }
        // else{
        //     for(int i = 0; i<ans.size(); i++){
        //         ans[i] = mul/nums[i];
        //     }
        // }
        // return ans;

        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1; i<nums.size(); i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        int right_prod = 1;

        for(int i = nums.size()-1; i>=0; i--){
            ans[i] = ans[i]*right_prod;
            right_prod = right_prod*nums[i];
        }
        return ans;
    }
};