class Solution {
public:
    vector<string> gettokens(string version){
        stringstream ss(version);

        string token = "";
        vector<string> tokens;
        while(getline(ss,token,'.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 =  gettokens(version1);
        vector<string> v2 = gettokens(version2);

        int n = v1.size();
        int m = v2.size();
        int i = 0;
        while(i<n || i<m){
            int a = i<n ? stoi(v1[i]):0;
            int b = i<m ? stoi(v2[i]):0;

            if(a>b){
                return 1;
            }
            else if(a<b){
                return -1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};