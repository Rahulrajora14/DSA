// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;
double dp[3005][3005];
int help(vector<double>&probability , int x,int i){
    if(x==0) return 1;
    if(i==-1) return 0;
    if(dp[i][x]>-0.9) return dp[i][x];
    return dp[i][x]= help(probability,x-1,i-1)*probability[i] + help(probability,x,i-1)*(1-probability[i]);
    
}

int main() {
    memset(dp,-1,sizeof dp);
    int n=0;
    cin>>n;
    vector<double>probability(n);
    for(int i=0;i<n;i++){
        cin>>probability[i];
    }
    cout<<fixed<<setprecision(9)<<help(probability,(n+1)/2,n-1);
    
    

    return 0;
}