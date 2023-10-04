#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjlist;
    void addEdge(int u,int v,int load){
        pair<int,int> p = make_pair(v,load);
        adjlist[u].push_back(p);
    }
    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s){
        visited[node] = true;
        for(auto i:adjlist[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }
    void smallpath(int src,vector<int> &distance,stack<int>&s){
        distance[src] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(distance[top] != INT_MAX){
                for(auto i:adjlist[top]){
                    if(distance[top]+i.second <distance[i.first]){
                        distance[i.first] = distance[top]+i.second;
                    }
                }
            }
        }

    }
};

int main(){
    graph G;
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);
    G.print();

    unordered_map<int,bool> visited;
    int n =6;
    stack<int> s;
    for(int i=0;i<n; i++){
        if(!visited[i]){
            G.dfs(i,visited,s);
        }
    }
    int src = 1;
    vector<int> distance(n,INT_MAX);
    for(int i=0; i<n; i++){
        distance[i]=INT_MAX;
    }
    G.smallpath(src,distance,s);
    for(int i=0; i<n; i++){
        cout<<distance[i]<<" ";
    }cout<<endl;


}