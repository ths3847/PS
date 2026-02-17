#include <bits/stdc++.h>
using namespace std;
int N,M,C,dp[51][51][51][51];
int v[51][51];
int go(int n, int m, int c, int prev){
    if(n>N || m>M) return 0;
    if(n==N&&m==M){
        if(c==1&&v[n][m]>prev) return 1;
        if(v[n][m]==0 && c==0) return 1;
        return 0;
    }
    int &ret = dp[n][m][c][prev];
    if(ret!=-1) return ret;
    ret=0;
    if(!v[n][m])
        ret += (go(n+1,m,c,prev)+ go(n,m+1,c,prev))%1000007;
    else if(v[n][m] > prev)
        ret += (go(n+1,m,c-1,v[n][m])+ go(n,m+1,c-1,v[n][m]))%1000007;
    return ret;
}
int main(){
    cin >> N >> M >> C;
    int cnt=0;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<C;i++){
        int n, m;
        cin >> n >> m;
        v[n][m] = ++cnt;
    }
    for(int i=0;i<=C;i++){
        cout << go(1,1,i,0) << " ";
    }
    return 0;
}