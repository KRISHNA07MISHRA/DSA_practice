class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        vector<int> result;
        unordered_map<int,int> mp;
        for(int i = 0; i<ans.size(); i++){
            mp[ans[i]]++;
        }
        for(auto temp:mp){
            result.push_back(temp.first);
        }
        return result;
    }
};