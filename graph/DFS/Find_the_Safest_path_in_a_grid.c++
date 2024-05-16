class Solution {
public:
    vector<vector<int>> adj{{0,1},{0,-1},{1,0},{-1,0}};
    bool check(vector<vector<int>>&safefactor, int sf){
        if(safefactor[0][0] < sf)
            return false;
        int n = safefactor.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty()){
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();

            if(curr_i == n-1 && curr_j == n-1){
                return true;
            }
            for(int i = 0; i<adj.size(); i++){
                int new_i = curr_i + adj[i][0];
                int new_j = curr_j + adj[i][1];

                if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && visited[new_i][new_j] != true){
                    if(safefactor[new_i][new_j]<sf){
                        continue;
                    }
                    else{
                        q.push({new_i,new_j});
                        visited[new_i][new_j] = true;
                    }
                }
            }
        }
        return false;

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safefactor(n,vector<int>(n,-1));

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size-->0){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                safefactor[curr_i][curr_j] = level;
                for(int i = 0; i<adj.size(); i++){
                    int new_i = curr_i+adj[i][0];
                    int new_j = curr_j + adj[i][1];

                    if(new_i<0 || new_i>=n || new_j<0 || new_j>=n || visited[new_i][new_j] == true){
                        continue;
                    }
                    else{
                        q.push({new_i,new_j});
                        visited[new_i][new_j] = true;
                    }
                }

            }
            level++;
        }


        int start = 0;
        int end = 400;
        int result = 0;
        while(start<=end){
            int mid = start + ((end-start)/2);

            if(check(safefactor,mid)){
                result = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return result;
    }
};