#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class DSU{
    vector<int> parent;
    vector<int> rank;
    int noofcomponent;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        noofcomponent = n;
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(i == parent[i]){
            return i;
        }

        return parent[i] = find(parent[i]);
    }
    void UNION(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
        if(parent_u != parent_v){
            if(rank[parent_u]>rank[parent_v]){
                parent[parent_v] = parent_u;
            }
            else if(rank[parent_u]<rank[parent_v]){
                parent[parent_u] = parent_v; 
            }
            else{
                parent[parent_u] = parent_v;
                rank[parent_v]++;
            }
            noofcomponent--;
        }
    }
    int occurance(){
        return noofcomponent;
    }

};
bool solve(vector<int>&nums){
    int n = nums.size();
    unordered_map<int,int> mp;
    DSU dsu(n);
    for(int i = 0; i<n; i++){
        for(int factor = 2; factor*factor<=nums[i]; factor++){
            if(nums[i]%factor != 0){
                continue;
            }
            if(mp.find(factor) != mp.end()){
                int idx = mp[factor];
                dsu.UNION(idx,i);
            }
            else{
                mp[factor] = i;
            }
            while(nums[i]%factor == 0){
                nums[i] = nums[i]/factor;
            }
        }
        if(nums[i]>1){
            if(mp.find(nums[i]) != mp.end()){
                int idx = mp[nums[i]];
                dsu.UNION(idx,i);
            }
            else{
                mp[nums[i]] = i;
            }
        }
    }
    return dsu.occurance() == 1;
}
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        ans.push_back(a);
    }
    cout<< solve(ans)<< endl;
}