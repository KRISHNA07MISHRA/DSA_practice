#include<bits/stdc++.h>
#include<vector>
using namespace std;


bool check(vector<char>& occurance){
    for(auto &i:occurance){
        if(i != 0){
            return false;
        }
    }
    return true;
}
int anagrams(string txt, string pattern){

    vector<char> occurance(26,0);

    for(int i = 0; i<pattern.length(); i++){
        char element = pattern[i]-'a';

        occurance[element]++;
    }

    int n = txt.length();

    int i, j;
    i = j = 0;
    int count = 0;
    while(j<n){
        occurance[txt[j]-'a']--;
        if(j-i+1 == pattern.length()){
            if(check(occurance)){
                count++;
            }
            occurance[txt[i]-'a']++;
            i++;
        }

        j++;
    }
    return count;

}
int main(){
    string a,b;

    cin>> a>> b;

    cout<<anagrams(a,b)<<endl;
}