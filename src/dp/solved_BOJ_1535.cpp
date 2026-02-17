#include <bits/stdc++.h>
using namespace std;
int dp[101];
vector<int> a;
vector<int> b;
int N;
int main(){
    cin >> N;
    a.assign(N,0);
    b.assign(N,0);
    for(int i=0;i<N;i++)
        cin >> a[i];
    for(int i=0;i<N;i++)
        cin >> b[i];
    for(int i=0;i<N;i++){
        if(a[i] == 100) continue;
        for(int j=99;j>=a[i];j--)
            dp[j] = max(dp[j], dp[j-a[i]]+b[i]);
    }
    if(dp[99]) cout << dp[99];
    else cout << 0;
    return 0;
}