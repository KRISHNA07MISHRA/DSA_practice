class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;

        int count = 0;
        int product = 1;
        if(k<=1){
            return 0;
        }
        while(j<nums.size()){
            product *= nums[j];

            while(product>=k && i<=j ){
                product /= nums[i];
                i++;
            }

            count += (j-i)+1;
            j++;
        }

        return count;
    }
};