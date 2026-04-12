class Solution {
public:
int f(int n,vector<int>&dp){
    if (n==0||n==1) return 1;
    if(n==2) return 2;
    if(dp[n]!=-1)return dp[n];
    int result =0;
    for(int i = 1; i<=n ; i++){
        result = result +f(i-1,dp)*f(n-i,dp);
    }
    return dp[n]= result;
}
    int numTrees(int n) {
        vector<int> dp(n+1,-1);

        return f(n,dp);
        
    }
};