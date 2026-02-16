#include <bits/stdc++.h>
using namespace std;
int dp[10001];

int main(){
    int n, m1, m2;
    while(1){
        scanf("%d %d.%d", &n, &m1, &m2);
        int cost = m1*100+m2;
        if(n==0&&cost==0) break;
        memset(dp,0,sizeof(dp));

        for(int j=0;j<n;j++){
            int ntmp, mtmp, m1,m2;
            scanf("%d %d.%d", &ntmp, &m1, &m2);
            mtmp = m1*100+m2;
            for(int i=mtmp;i<=cost;i++){
                dp[i] = max(dp[i], dp[i-mtmp]+ntmp);
            }
        }
        cout << dp[cost] << endl;

    }

    return 0;
}