#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int v[10][10];
int a[6] = {0,5,5,5,5,5};
int ret=INF;

bool check(int x, int y, int n){
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(i>=10 || j>=10) return false;
            if(!v[i][j]) return false;
        }
    }
    return true;
}

void change(int x, int y, int n){
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++)
            v[i][j] = 0;
    }
}

void dfs(int cnt){
    if(cnt >= ret) return;
    int x(-1), y(-1);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(v[i][j]){
                x = i;
                y = j;
                break;
            }
        }
        if(x!=-1) break;
    }
    if(x==-1) {
        ret = min(ret,cnt);
        return;
    }
    for(int i=5;i>=1;i--){
        if(!a[i]) continue;
        if(!check(x,y,i)) continue;
        a[i]--;
        int tmp[10][10];
        memcpy(tmp,v,sizeof(v));
        change(x,y,i);
        dfs(cnt+1);
        a[i]++;
        memcpy(v,tmp,sizeof(v));
    }
}

int main(){
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cin >> v[i][j];
    }
    int cnt=0;
    for(auto tmp : v)
        cnt += accumulate(tmp, tmp+10,0);
    if(!cnt){
        cout << cnt;
        return 0;
    }

    dfs(0);
    if(ret==INF) cout << -1;
    else cout << ret;
    return 0;
}