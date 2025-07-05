class Solution {
public:
    vector<vector<long long>> adj = {{0,1},{1,0}};
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        vector<vector<long long>> arr(n,vector<long long>(m,LLONG_MAX));
        arr[0][0] = 1;
        // row, col, cost;
        priority_queue<pair<long long,pair<long long,long long>>, vector<pair<long long,pair<long long,long long>>>, greater<pair<long long,pair<long long,long long>>>> pq;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            long long row = pq.top().first;
            long long col = pq.top().second.first;
            long long cost = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1){
                return cost-waitCost[row][col];
            }

            for(auto temp:adj){
                long long newr = row+temp[0];
                long long newc = col+temp[1];

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    long long newcost = cost + 1LL*((newr+1)*(newc+1))+waitCost[newr][newc];
                    if(arr[newr][newc]>newcost){
                        arr[newr][newc] = newcost;
                        pq.push({newr,{newc,newcost}});
                    }
                }
            }
        }
        return -1;
    }
};