#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> dp(k+1);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp>10000) continue;
        dp[tmp]++;
        for(int j=tmp+1;j<=k;j++){

            if(dp[j-tmp]) dp[j] += dp[j-tmp];
        }
    }
    cout << dp[k];
    
}