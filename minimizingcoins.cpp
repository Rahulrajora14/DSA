#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int>coins;
vector<int>dp(1000006,-2);
int f(int x){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result= INT_MAX;
    for(int i=0;i<(int)coins.size();i++){
        if(x-coins[i]<0) continue;
        result= min(result,f(x-coins[i]));
    }
    if(result==INT_MAX) return dp[x] = INT_MAX;
    return dp[x]=1+result;
}


int main() {
    int n;
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    if(f(x) == INT_MAX) cout<<-1;
    else{
        cout<<f(x);
    }

    return 0;
}