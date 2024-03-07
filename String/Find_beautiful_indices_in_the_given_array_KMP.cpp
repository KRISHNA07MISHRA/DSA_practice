class Solution {
public:
    void findlps(string pattern, vector<int>&lps){
        int m = pattern.length();
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while(i<m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> findindex(string txt, string pattern){
        int M = pattern.length();
        int N = txt.length();

        vector<int> lps(M,0);
        vector<int> ans;
        findlps(pattern,lps);

        int i= 0;
        int j = 0;
        while(i<N){
            if(txt[i] == pattern[j]){
                i++;
                j++;
            }
            if(j == M){
                ans.push_back(i-M);
                j = lps[j-1];
            }
            else if(txt[i] != pattern[j]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> finda = findindex(s,a);
        vector<int> findb = findindex(s,b);

        vector<int> ans;
        int n = s.length();
        for(auto it:finda){
            int left_index = max(0,it-k);
            int right_index = min(n-1,it+k);
            if(findb.find(left_index))
        }
        return ans;
    }
};