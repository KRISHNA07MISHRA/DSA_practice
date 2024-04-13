class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;

        while(i < height.size() && height[i] == 0){
            i++;
        }
        int j = i;
        int ans = 0;

        while(j<height.size()){
            j = i+1;
            while(j < height.size() && height[j] < height[i]){
                j++;
            }
            if(j == height.size()){
                break;
            }
            
            int from = height[i];
            for(int k = i+1; k<j; k++){
                ans += from - height[k];
            }
            i = j;
        }
        int v = height.size()-1;
        while(v >= 0 && height[v] == 0){
            v--;
        }
        int u = v;
        while(u>0){
            u = v-1;
            while(u >= 0 && height[u] <= height[v]){
                u--;
            }
            if(u <0){
                break;
            }
            int from = height[v];
            for(int k = v; k>u; k--){
                ans += from-height[k];
            }
            v = u;
        }


        return ans;

        
    }
};