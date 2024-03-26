class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<nums.size(); i++){
            int no = abs(nums[i]);

            int idx = no-1;

            if(nums[idx]<0){
                return no;
            }

            nums[idx] *= -1;

        }

        return -1;
    }
};