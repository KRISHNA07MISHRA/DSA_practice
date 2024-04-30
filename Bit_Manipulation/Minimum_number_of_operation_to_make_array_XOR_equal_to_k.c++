class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int num = 0;
        for(int i = 0; i<nums.size(); i++){
            num ^= nums[i];
        }

        int diff = num^k;
        return __builtin_popcount(diff);
    }
};