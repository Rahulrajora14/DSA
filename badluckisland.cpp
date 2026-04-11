#include <iostream>
#include <vector>
#define ld long double
#include <cstring>
#include <iomanip>
using namespace std;

ld dp[105][105][105];

ld island(int r, int p, int s){
    if(r==0 || s==0) return 0.0;
    if(p==0) return 1.0;

    if(dp[r][p][s] > -0.9) return dp[r][p][s];

    ld total = (ld)r*p + p*s + r*s;
    ld ans = 0.0;

    // paper kills rock
    ans += island(r-1, p, s) * ((ld)r*p / total);

    // rock kills scissors
    ans += island(r, p, s-1) * ((ld)r*s / total);

    // scissors kills paper
    ans += island(r, p-1, s) * ((ld)p*s / total);

    return dp[r][p][s] = ans;
}

ld islandp(int r, int p, int s){
    if(p==0 || r==0) return 0.0;
    if(s==0) return 1.0;

    if(dp[r][p][s] > -0.9) return dp[r][p][s];

    ld total = (ld)r*p + p*s + r*s;
    ld ans = 0.0;

    ans += islandp(r-1, p, s) * ((ld)r*p / total);
    ans += islandp(r, p, s-1) * ((ld)r*s / total);
    ans += islandp(r, p-1, s) * ((ld)p*s / total);

    return dp[r][p][s] = ans;
}

ld islands(int r, int p, int s){
    if(s==0 || p==0) return 0.0;
    if(r==0) return 1.0;

    if(dp[r][p][s] > -0.9) return dp[r][p][s];

    ld total = (ld)r*p + p*s + r*s;
    ld ans = 0.0;

    ans += islands(r-1, p, s) * ((ld)r*p / total);
    ans += islands(r, p, s-1) * ((ld)r*s / total);
    ans += islands(r, p-1, s) * ((ld)p*s / total);

    return dp[r][p][s] = ans;
}

int main() {
    int r,p,s;
    cin>>r>>p>>s;

    memset(dp,-1,sizeof dp);
    ld ansr = island(r,p,s);

    memset(dp,-1,sizeof dp);
    ld ansp = islandp(r,p,s);

    memset(dp,-1,sizeof dp);
    ld anss = islands(r,p,s);

    cout << fixed << setprecision(9) << ansr << " " << ansp << " " << anss;
}