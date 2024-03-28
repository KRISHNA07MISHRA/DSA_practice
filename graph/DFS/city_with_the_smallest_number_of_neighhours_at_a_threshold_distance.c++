  public:
    void diskjtra(int source, vector<int>& list, unordered_map<int, vector<pair<int,int>>>& adj){
        queue<pair<int,int>> q;
        q.push({source, 0});
        
        while (!q.empty()) {
            int src = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for (auto temp : adj[src]) {
                int node = temp.first;
                int weight = temp.second;
                
                if (list[node] > dis + weight) {
                    list[node] = dis + weight;
                    q.push({node, dis + weight});
                }
            }
        }
    }
    
    int howmanyhouse(int node, unordered_map<int,vector<pair<int,int>>>& mp, int& n, int &dist) {
        vector<int> list(n, INT_MAX);
        list[node] = 0;
        diskjtra(node,list,mp);
        // queue<pair<int,int>> q;
        // q.push({node, 0});
        
        // while (!q.empty()) {
        //     int src = q.front().first;
        //     int dis = q.front().second;
        //     q.pop();
            
        //     for (auto temp : mp[src]) {
        //         int node = temp.first;
        //         int weight = temp.second;
                
        //         if (list[node] > dis + weight) {
        //             list[node] = dis + weight;
        //             q.push({node, dis + weight});
        //         }
        //     }
        // }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (list[i] != 0 && list[i] <= dist) { 
                count++;
            }
        }
        
        return count;
    }
    
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> mp;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            ans[i] = howmanyhouse(i, mp, n, distanceThreshold);
        }
        
        int result = INT_MAX;
        int val = -1;
        for(int i = 0; i<n; i++){
            if(result>=ans[i]){
                result = ans[i];
                val = i;
            }
        }
        return val;
    }

};