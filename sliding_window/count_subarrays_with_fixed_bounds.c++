class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini = -1;
        int maxi = -1;
        int chor = -1;
        long long ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK){
                chor = i;
            }

            if(nums[i] == minK){
                mini = i;
            }
            if(nums[i] == maxK){
                maxi = i;
            }
            int temp = min(mini,maxi);
            int val = temp- chor;
            if(val<0){
                ans += 0;
            }
            else
                ans += val;
        }
        return ans;
    }
};