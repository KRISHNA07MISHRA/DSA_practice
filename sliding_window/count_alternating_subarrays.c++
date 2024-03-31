class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int j = i;

            while (j + 1 < n && nums[j] != nums[j + 1]) {
                ++j;
            }

            int len = j - i + 1;
            count += (long long)len * (len + 1) / 2;
            i = j;
        }

        return count;
    }
};