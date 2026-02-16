#include <bits/stdc++.h>
using namespace std;
int T, W;
int dp[1001][31][2];
vector<int> v;

int down(int t,int w, int here){
    if(t==T) return 0;
    int &ret = dp[t][w][here];
    if(ret != -1) return ret;
    int res, moved_res;
    if(v[t]==here) res=1;
    else res=0;
    moved_res = res^1;
    res += down(t+1,w,here);
    if(w>0){
        moved_res += down(t+1,w-1, here^1);
        ret = max(res, moved_res);
    }
    else
        ret = res;
    return ret;
}

int main(){
    cin >> T >> W;
    v.assign(T,0);
    for(int i=0;i<T;i++){
        cin >> v[i];
        v[i]--;
    }
    memset(dp, -1, sizeof(dp));
    int result = down(0,W,0);
    int move=-1;
    if(W>0)
        move = down(0,W-1,1);
    result = max(result, move);
    cout << result;
    return 0;
}