class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){
            int no = abs(nums[i]);

            int idx = no-1;

            if(nums[idx]<0)
                ans.push_back(no);
            
            nums[idx] *= -1;
        }

        
        return ans;
    }
};