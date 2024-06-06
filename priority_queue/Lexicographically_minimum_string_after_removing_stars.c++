class Solution {
public:
    
priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

void solve(string& ans) {
    int index = -(pq.top().second);
    ans[index] = '+';
    pq.pop();
}

string clearStars(string s) {


    int i = 0;
    string ans = "";
    while (i < s.length()) {
        if (s[i] == '*') {
            solve(ans);
        } else {
            ans += s[i];
            pq.push({s[i], -(ans.length()-1)});
        }
        i++;
    }

    string result = "";
    for(int i = 0; i<ans.length(); i++){
        if(ans[i] != '+'){
            result += ans[i];
        }
    }
    return result;
}

};