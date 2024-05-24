class Solution {
public: 
   
    void  solve(int &count, vector<int>&nums,int& k, int index,unordered_map<int,int>&mp){
        if(index>=nums.size()){
            count++;
           
            return  ;
        }

        if(!mp[nums[index]-k]){
            mp[nums[index]]++;
           
            solve(count,nums,k,index+1,mp);

            mp[nums[index]]--;
            
           

        }
        solve(count,nums,k,index+1,mp);

       
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
       
        int val = 0;
      

      
        solve(val,nums,k,0,mp);
       
       

        return val-1;
    }
};