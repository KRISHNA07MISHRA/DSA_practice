class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long int> pq;
        
        for(int i = 0; i<happiness.size(); i++){
            pq.push(happiness[i]);
        }
        long long int val = 0;
        long long int i = 0;
        while(k>0){
            int term = pq.top()-i;
            if(term>=0){
                val += term;
            }
            pq.pop();
            i++;
            k--;
            
        }
        return val;
    }
};