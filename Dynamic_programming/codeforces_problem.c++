#include <iostream>
#include <vector>      
#include <algorithm>   
#include <string>      
#include <map>         
#include <set>         
#include <queue>       
#include <stack>       
#include <cmath>       
#include <limits>
#include <limits.h>      
#include <unordered_map> 
using namespace std;

long long result(vector<long long>&temp, int index, bool flag,vector<vector<long long>>&dp){
    if(index == temp.size()-1){

        if(flag == true){
            return -temp[index];
        }
        else{
            return temp[index];
        }
    }
    if(dp[index][flag] != -1){
        return dp[index][flag];
    }

    long long with = 0;
    long long without = 0;

    if(flag == false){
        with = temp[index] + result(temp,index+1,flag,dp);
        without = (-temp[index])+ result(temp,index+1,true,dp);
    }
    if(flag == true){
        with = (-temp[index]) + result(temp,index+1,false,dp);
        without = (temp[index]) + result(temp,index+1,true,dp);
    }

    return dp[index][flag] =  max(with,without);
}
long long solve(vector<long long>&temp){
    int n = temp.size();
    vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
    return result(temp,0,false,dp);
}

int main() {

    long long n;
    cin>>n;
    
    for(int i = 0; i<n; i++){
        long long a;
        cin>>a;
        vector<long long> temp;
        for(int j = 0; j<a; j++){
            long long b;
            cin>>b;
            temp.push_back(b);
        }

        cout<<solve(temp)<<endl;
    }
    
}

