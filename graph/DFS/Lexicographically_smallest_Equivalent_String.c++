class Solution {
public:
    char dfs(unordered_map<char, vector<char>>&adj, char curr, vector<int> &visited){
        visited[curr-'a'] = 1;

        char ch = curr;
        for(auto temp:adj[curr]){
            if(visited[temp-'a'] == 0){
                ch = min(ch,dfs(adj,temp,visited));
            }
        }
        return ch;
        
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;

        for(int i = 0; i<s1.length(); i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans; 

        for(int i= 0; i<baseStr.length(); i++){
            vector<int> visited(26,0);

            char minichar = dfs(adj,baseStr[i],visited);

            ans.push_back(minichar);
        }
        return ans;
    }
};