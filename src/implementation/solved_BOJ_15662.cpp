#include <bits/stdc++.h>
using namespace std;
int visited[1001];
vector<string> v;
int N,K;

//6...2 <-> 6...2 <-> 6...2
void dfs(int n, int d){
    visited[n] = 1;

    if(n-1>=0&&visited[n-1]==0&&v[n][6]==v[n-1][2]^1)
        dfs(n-1, d*-1);
    if(n+1<N&&visited[n+1]==0&&v[n][2]==v[n+1][6]^1)
        dfs(n+1, d*-1);
        
    if(d==1)
        rotate(v[n].begin(),v[n].end()-1,v[n].end());
    else
        rotate(v[n].begin(),v[n].begin()+1,v[n].end());
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> K;
    for(int i=0;i<K;i++){
        memset(visited, 0 ,sizeof(visited));
        int n, d;
        cin >> n >> d;
        dfs(n-1, d);
    }
    int ret=0;
    for(int i=0;i<N;i++)
        ret += v[i][0]-'0';
    cout << ret;
    return 0;
}