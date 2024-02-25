#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    vector<int> parent;
    vector<int>rank;
    
    int find(int i ){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    
    void UNION(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
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
        
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V,0);
	    
	    for(int i = 0; i<V; i++){
	        parent[i] = i;
	        
	    }
	    
	    for(int u = 0; u<V; u++){
	        for(auto &V:adj[u]){
	            if(u<V){
	            int parent_u = find(u);
	            int parent_v= find(V);
	            
	            if(parent_u == parent_v){
	                return true;
	            }
	            else{
	                UNION(parent_u,parent_v);
	            }
	            }
	        }
	    }
	    return false;
	    
	}


};




int main(){
    int tc;
    cin>> tc;
    while(tc--){
        int V,E;
        cin>>V>> E;
        vector<int> adj[V];
        for(int i = 0; i<E; i++){
            int u, v;
            cin>> u>> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V,adj);
        cout<<ans<<"\n";
    }
    return 0;
}
