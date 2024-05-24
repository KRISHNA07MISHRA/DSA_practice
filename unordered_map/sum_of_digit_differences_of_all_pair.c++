class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string> st;
        for(int i = 0; i<nums.size(); i++){
            string val = to_string(nums[i]);
            st.push_back(val);
        }
        long long ans = 0;
        int digit = st[0].length();
        for(int position = 0; position<digit; position++){
            unordered_map<char,long long> mp;
            for(int ele = 0; ele < st.size(); ele++){
                mp[st[ele][position]]++;
            }

            for(auto temp:mp){
                ans += temp.second * (st.size()-temp.second);
            }
        }
        return ans/2;
    }
};