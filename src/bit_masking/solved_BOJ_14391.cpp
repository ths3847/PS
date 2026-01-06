#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> v;
int ret;
vector<vector<int>> visited(4, vector<int>(4));
void dfs(int x,int y, int n){
    ret = (ret*10+v[x][y]);
    visited[x][y] = 1;
    if(n&(1<<(M*x+y))){
        int ny = y+1;
        if(ny < M && visited[x][ny]==0 && n&(1<<(M*x+ny)))
            dfs(x,ny,n);
    }
    else{
        int nx = x+1;
        if(nx < N && visited[nx][y]==0 && !(n&(1<<(M*nx+y))))
            dfs(nx,y,n);
    }
}
int main(){
    cin >> N >> M;
    int mx=0;
    for(int i=0;i<N;i++){
        vector<int> tmpv;
        string str;
        cin >> str;
        for(int j=0;j<M;j++)
            tmpv.push_back(str[j]-'0');
        v.push_back(tmpv);
    }
    for(int i=0;i<1<<(N*M);i++){
        int total=0;
        for(auto &tmp : visited) fill(tmp.begin(), tmp.end(),0);
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(visited[j][k]!=0) continue;
                ret = 0;
                dfs(j,k,i);
                total+=ret;
            }
        }
        mx = max(mx,total);
    }
    cout << mx;
    return 0;
}