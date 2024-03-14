class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i , j;
        i = j = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        int noofzero = 0;
        while(j<n){
            sum += nums[j];
            while(i<j && (nums[i]==0 || sum > goal)){
                if(nums[i] == 0){
                    noofzero++;
                }
                else{
                    noofzero = 0;
                }
                sum -= nums[i];
                i++;
            }


            if(sum == goal){
                count = count+1+noofzero;
            }
            j++;
        }
        return count;
    }
};