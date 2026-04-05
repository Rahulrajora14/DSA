#define ll long long int
#define mod 1000000007
class Solution {
public:
vector<vector<int> > dp ;
ll help(int n,int k, int t){
    if(n==0 && t==0)return 1;
    if(n==0) return 0;
    if(dp[n][t]!=-1)return dp[n][t];
    int count =0;
    for(int v=1;v<=k;v++){
        if(t-v<0)continue;
        count = (count + help(n-1,k,t-v))% mod;
    }
    return dp[n][t]=count;
}
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35, vector<int>(1005, -1));

        return help(n,k,target);
        
    }
};