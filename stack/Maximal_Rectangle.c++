class Solution {
public:
    vector<int> getNSR(vector<int>&height){
        stack<int> st;
        int n = height.size();
        vector<int> nsr(n);
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                nsr[i] = n;
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }
                else{
                    nsr[i] = st.top();
                }
            }

            st.push(i);
        }

        return nsr;
    }

    vector<int> getLSR(vector<int>&height){
        stack<int>st;
        int n = height.size();
        vector<int> nsl(n);
        for(int i = 0; i<n; i++){
            if(st.empty()){
                nsl[i] = -1;
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }
                else{
                    nsl[i] = st.top();
                }
            }
            st.push(i);
        }
        return nsl;
    }
    int find(vector<int>&height){

        // find next least right
        // find next least left

        vector<int> NSR = getNSR(height);
        vector<int> LSR = getLSR(height);

        vector<int> wedth(height.size());

        for(int i = 0; i<height.size(); i++){
            wedth[i] = NSR[i]-LSR[i]-1;
        }
        int ans = 0;
        for(int i = 0; i<height.size(); i++){
            ans = max(ans,wedth[i]*height[i]);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int n = matrix.size();

        int m = matrix[0].size();

        vector<int> height(m);
        for(int i = 0; i<m; i++){
            if(matrix[0][i] == '1'){
                height[i] = 1;
            }
            else{
                height[i] = 0;
            }
        }
        int maxArea = find(height);
        

        for(int row = 1; row<n; row++){
            for(int col = 0; col<m; col++){
                if(matrix[row][col] == '0'){
                    height[col] = 0;
                }
                else{
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea,find(height));
        }

        return maxArea;


    }
};