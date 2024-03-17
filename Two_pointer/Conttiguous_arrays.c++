class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int curr_sum = 0;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                curr_sum += (-1);
                if(mp.find(curr_sum) != mp.end()){
                    int prev_index = mp[curr_sum];
                    ans = max(ans,i-prev_index);
                }
                else
                    mp[curr_sum] = i;
            }
            else{
                curr_sum += 1;
                if(mp.find(curr_sum) != mp.end()){
                    int prev_index = mp[curr_sum];
                    ans = max(ans,i-prev_index);
                }
                else
                    mp[curr_sum] = i;
            }
        }
        return ans;
    }
};