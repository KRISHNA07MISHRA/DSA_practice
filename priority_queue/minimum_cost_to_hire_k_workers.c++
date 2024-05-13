class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,double>> qualityratio;
        for(int i = 0; i<quality.size(); i++){
            double val = (double)wage[i]/quality[i];
            qualityratio.push_back({val,quality[i]});
        }
        sort(qualityratio.begin(),qualityratio.end());

        double ans = DBL_MAX;

        priority_queue<double> pq;
        double sum = 0;
        for(int i = 0; i<k; i++){
            pq.push(qualityratio[i].second);
            sum += qualityratio[i].second;
        }
        double managerratio = qualityratio[k-1].first;
        ans = managerratio*sum;
        for(int manager =k; manager<qualityratio.size(); manager++ ){
            double newmangerratio = qualityratio[manager].first;
            
            pq.push(qualityratio[manager].second);
            sum += qualityratio[manager].second;
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            
            ans = min(ans,newmangerratio*sum);
        }
        return ans;
    }
};