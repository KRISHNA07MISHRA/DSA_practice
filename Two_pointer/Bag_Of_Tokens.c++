class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int i = 0;
        int j = n-1;
        vector<int> ans;
        while(i<=j){
            if(power>=tokens[i]){
                power = power - tokens[i];
                i++;
                score++;
                ans.push_back(score);
            }
            else if(power<tokens[i] && score>0){
                power += tokens[j];
                j--;
                score--;
            }
            else{
                i++;
                j--;
            }
        }
        int result = 0;
        for(int i = 0; i<ans.size(); i++){
            result = max(result,ans[i]);
        }
        return result;
    }
};