class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool onecontain = false;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                onecontain = true;
            }

            if(nums[i]<=0 || nums[i]>n){
                nums[i] = 1;
            }
        }

        if(onecontain == false){
            return 1;
        }

        for(int i = 0; i<nums.size(); i++){
            int no = abs(nums[i]);

            int idx = no-1;

            if(nums[idx]<0)
                continue;

            nums[idx] *= -1;

        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};