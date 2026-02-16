#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int dp[100001];
int n,k;
int main(){
    cin >> n >> k;
    fill(dp, dp+100001, INF);
    vector<int> v;
    for(int i =0;i<n;i++){
        int tmp;
        cin >> tmp;
        dp[tmp] = 1;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=1;i<=k;i++){
        if(dp[i] == 1) continue;
        int &ret = dp[i];
        for(int j=0;j<v.size();j++){
            if((i-v[j])>0)
                ret = min(ret, dp[i-v[j]]+1);
            else
                break;
        }
    }
    if(dp[k]>=INF) cout << -1;
    else cout << dp[k];
    return 0;
}