class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<long long,vector<pair<long long,pair<long long,long long>>>> adj;
        for(int i = 0; i<edges.size(); i++){
            long long u = edges[i][0];
            long long v = edges[i][1];
            long long start = edges[i][2];
            long long end = edges[i][3];

            adj[u].push_back({v,{start,end}});
        }
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<int> destination(n,INT_MAX);
        pq.push({0,0});
        destination[0] = 0;
        while(!pq.empty()){

            long long value = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            if(node == n-1){
                return value;
            }
            
            for(auto temp:adj[node]){
                long long nextnode = temp.first;
                long long neededstart = temp.second.first;
                long long neededend = temp.second.second;

                if(value>=neededstart && value<=neededend){
                    if(destination[nextnode]>value+1){
                        destination[nextnode] = value+1;
                        pq.push({value+1,nextnode});
                    }
                    //pq.push({value+1,nextnode});
                }

                if(value<neededstart){
                    if(destination[nextnode]>neededstart+1){
                        destination[nextnode] = neededstart+1;
                        pq.push({neededstart+1,nextnode});
                    }
                    //pq.push({neededstart+1,nextnode});
                }
            }
        }
        return -1;
    }
};