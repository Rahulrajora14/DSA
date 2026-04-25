class Solution {
public:
int dp[1005][102][2];
int help(vector<int> & price, int i,int k,bool on){
    if(i>=price.size()) return 0;
    if (dp[i][k][on]!=-1)return dp[i][k][on];
    int ans= INT_MIN;a
    ans  = help(price,i+1,k,on);
    if(on){
        ans = max(ans,price[i]+help(price,i+1,k-1,false));
    }
    else{
        if(k>0){
            ans = max(ans,help(price,i+1,k,true)-price[i]);
        }
    }
    return dp[i][k][on]=ans;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return help(prices,0,k,false);
    }
};