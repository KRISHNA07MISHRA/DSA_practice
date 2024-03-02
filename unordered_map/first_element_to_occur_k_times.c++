   public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int> mp;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            mp[a[i]]++;
            ans[i] = mp[a[i]];
        }
        int index = -1;
        for(int i = 0; i<ans.size(); i++){
           if(ans[i] == k){
               index = i;
               break;
           }
        }
        if(index == -1){
            return -1;
        }
        return a[index];
        
    }
};