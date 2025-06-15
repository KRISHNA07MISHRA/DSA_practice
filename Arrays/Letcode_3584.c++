class Solution {
    public:
        long long maximumProduct(vector<int>& nums, int m) {
            int n = nums.size();
            vector<long long> mini(n);
            vector<long long> maxi(n);
    
            long long mininumber = INT_MAX;
            long long maxinumber = INT_MIN;
            for(int i = n-1; i>=0; i--){
                mininumber = min(mininumber,(long long)nums[i]);
                maxinumber = max(maxinumber,(long long)nums[i]);
    
                mini[i] = mininumber;
                maxi[i] = maxinumber;
            }
    
            long long result = -10000000000;
            for(int i = 0; i<n; i++){
                int last = i + m -1;
                if(last<n){
                    result = max({result, 
                   nums[i] * mini[last], 
                   nums[i] * maxi[last]});
    
                }
            }
            return result;
        }
    };