#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(int index, string &s, vector<string>&ans, string temp){
    if(index>= s.length()){
        if(temp != ""){
            ans.push_back(temp);
        }
        return ;
    }
    solve(index+1,s,ans,temp+s[index]);

    solve(index+1,s,ans,temp);
}
vector<string> powerset(string s){
    vector<string> ans;
    solve(0,s,ans,"");
    return ans;
}
int main(){
    string s;
    cin>> s;

    vector<string> ans = powerset(s);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}