class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i = 1; i<nums.size(); i++){
            int val = nums[i] - nums[i-1];
            if(val<=0){
                count += abs(val)+1;
                nums[i] = nums[i-1]+1;
            }
        }
        return count;
    }
};