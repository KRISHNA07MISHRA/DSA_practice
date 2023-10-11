#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<list>
void dfs(int node,int parent,int &count,vector<int>&disc,vector<int>&mini,unordered_map<int,bool>&visited,
unordered_map<int,list<int>>&adj,vector<int> &ans){
    visited[node] = true;
    disc[node] = mini[node] = count++;
    int child = 0;
    for(auto neighbour:adj[node]){
        if(neighbour == parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour,node,count,disc,mini,visited,adj,ans);
            mini[node] = min(mini[node],mini[neighbour]);

            if(mini[neighbour]>=disc[node]&& parent != -1){
                ans[node] = 1;
            }
            child++;
        }
        else {
            mini[node] = min(mini[node],disc[neighbour]); 
        }
        
    }
    if(parent == -1 && child>1){
        ans[node] = 1;
    }
}
int main(){
    int n = 5;
    int e = 5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    unordered_map<int,bool> visited;
    int count = 0;
    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }
    for(int i =0; i<n; i++){
        if(!visited[i]){
            dfs(i,parent,count,disc,low,visited,adj,ans);
        }
    }
    for(int i=0; i<n; i++){
        if(ans[i] != 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}