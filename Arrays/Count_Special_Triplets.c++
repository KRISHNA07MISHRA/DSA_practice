class Solution {
    public:
            int specialTriplets(vector<int>& nums) {
            const int MOD = 1000000007;
        
            unordered_map<long long, int> mp;
            unordered_map<int, int> freq;
            
        
            unordered_map<long long, int> prev;
            unordered_map<int, int> freq1;
            for (int i = nums.size() - 1; i >= 0; i--) {
                int val = nums[i];
                //string key = to_string(i) + to_string(val * 2);
                long long key = static_cast<long long>(i) * 100000 + val * 2;
    
                freq1[val]++;
                if (val == 0) {
                    prev[key] = freq1[val * 2] - 1;
                } else {
                    prev[key] = freq1[val * 2];
                }
            }
        
            long long count = 0;
            for (int i = 0; i < nums.size(); i++) {
                //string key = to_string(i) + to_string(nums[i] * 2);
                long long key = static_cast<long long>(i) * 100000 + nums[i] * 2;
    
                int val = nums[i];
                freq[val]++;
                if (val == 0) {
                    mp[key] = freq[val * 2] - 1;
                } else {
                    mp[key] = freq[val * 2];
                }
                int left = mp[key];
                int right = prev[key];
        
                count = (count+1LL  * left * right % MOD) % MOD;
                
            }
        
            return count;
        }
    };