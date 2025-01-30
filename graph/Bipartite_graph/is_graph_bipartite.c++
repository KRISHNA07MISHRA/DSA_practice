class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i<graph.size(); i++){
            vector<int> temp = graph[i];
            adj[i] = temp;

        }

        vector<int> value(n,-1);

        for(int i = 0; i<n; i++){
            if(value[i] == -1){
                value[i] = 0;
            }
            else{
                continue;
            }
            int val = value[i];
            queue<pair<int,int>> q;
            q.push({val,i});
            while(!q.empty()){
                int color = q.front().first;
                int num = q.front().second;
                q.pop();
                for(auto temp:adj[num]){
                    int second = value[temp];
                    if(color == second){
                                for(int i = 0; i<n; i++){
            cout<<value[i]<< " ";
        }
 
                        return false;
                    }
                    if(second == -1 && color == 1){
                        value[temp] = 0;
                        q.push({0,temp});
                    }
                    else if(second == -1 && color == 0){
                        value[temp] = 1;
                        q.push({1,temp});
                    }
                }
            }
            
        }
        for(int i = 0; i<n; i++){
            cout<<value[i]<< " ";
        }
        return true;
    }
};