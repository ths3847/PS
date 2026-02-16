#include <bits/stdc++.h>
using namespace std;
long long dp[31][61];
long long go(int o, int h){
    if(o==0) return 1;
    if(dp[o][h]!=-1) return dp[o][h];
    long long &ret = dp[o][h];
    if(h==0)
        ret = go(o-1,h+1);
    else
        ret = go(o, h-1) + go(o-1,h+1);
    return ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    while(1){
        int n;
        cin >> n;
        if(!n) break;
        cout << go(n,0) << endl;
    }
    return 0;
}