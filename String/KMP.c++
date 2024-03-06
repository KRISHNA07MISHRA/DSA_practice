class{
    public:
            void findlps(string pattern, vector<int>&lps,int m){
                int len = 0;
                
                lps[0] = 0;
                
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
            vector <int> search(string pattern, string text)
            {
                int M = pattern.length();
                int N = text.length();
                
                vector<int> LPS(M,0);
                
                findlps(pattern,LPS,M);
                vector<int> result;
                
                int i = 0; // text
                int j = 0; // pattern
                
                while(i<N){
                    if(pattern[j] == text[i]){
                        i++;
                        j++;
                    }
                    if(j == M){
                        result.push_back(i-M+1);
                        j = LPS[j-1];
                    }
                    else if(pattern[j] != text[i]){
                        if(j != 0){
                            j = LPS[j-1];
                        }
                        else{
                            i++;
                        }
                    }
                }
                return result;
            }
}