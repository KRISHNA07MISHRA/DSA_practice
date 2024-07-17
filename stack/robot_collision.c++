class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> actual_index(n);
        for(int i = 0; i<n; i++){
            actual_index[i] = i;
        }
        auto lambda = [&](int i, int j){
            return positions[i]<positions[j];
        };
        sort(actual_index.begin(),actual_index.end(), lambda); // sort on the basis of position 

        // we are accessing the index

        stack<int> st;
        for(auto index:actual_index){
            if(directions[index] == 'R'){// if someone goes left then we do not consider because it never collide to anyone
                st.push(index);
            }
            else{
                while(!st.empty() && healths[index]>0){ // if current index is left then at the top of index there is a index at which robot goes right
                    int top_index = st.top();
                    st.pop();

                    if(healths[top_index]>healths[index]){ // if the current robot who goes right is greater the curr robot who goes left then right kill the left robot and push into stack again
                        healths[top_index] -= 1;
                        healths[index] = 0;
                        st.push(top_index);
                    }
                    else if(healths[top_index]<healths[index]){// if left robot is more powerfull then right robot then it kill the robot untill the stack become empty and no need of push the left going robot into the stack
                        healths[index] -= 1;
                        healths[top_index] = 0;
                        
                    }
                    else{ // if both have same power then they kill each other
                        healths[index] = 0;
                        healths[top_index] = 0;
                    }
                }
                
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};