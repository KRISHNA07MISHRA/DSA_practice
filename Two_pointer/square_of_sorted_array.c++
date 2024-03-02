class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s = 0;
        int end = nums.size()-1;
        vector<int> ans(end+1);
        for(int i = nums.size()-1; i>=0; i--){
            if(abs(nums[s])>= abs(nums[end])){
                ans[i] = nums[s]*nums[s];
                s++;
            }
            else{
                ans[i] = nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};