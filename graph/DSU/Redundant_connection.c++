class Solution {
public:
    int find_parent(int value,vector<int>&parent){
        // base case 

        if(parent[value] == value){
            return value;
        }

        return parent[value] = find_parent(parent[value],parent);
    }

    void make_parent(int x, int y, vector<int>&parent, vector<int>&rank){
        int parent_x = find_parent(x,parent);
        int parent_y = find_parent(y,parent);

        if(parent_x == parent_y){
            return ;
        }

        int rank_x = rank[parent_x];
        int rank_y = rank[parent_y];

        if(rank_x > rank_y){
            parent[parent_y] = parent_x;
        }
        else if(rank_x < rank_y){
            parent[parent_x] = parent_y;
        }

        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }

        vector<int> rank(n+1,0);

        vector<int> ans;
        for(int i = 0; i<n; i++){
            int first = edges[i][0];
            int second = edges[i][1];
            cout<<parent[first]<<" "<<parent[second]<<"    "<<find_parent(first,parent)<<" "<<find_parent(second,parent)<<endl;

            if(find_parent(first,parent) == find_parent(second,parent)){
                ans.push_back(first);
                ans.push_back(second);
            }
            make_parent(first,second,parent,rank);
        }
        cout<<endl;
        for(int i = 0; i<parent.size(); i++){
            cout<<parent[i]<<" ";
        }
        return ans;
    }
};