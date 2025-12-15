#include <bits/stdc++.h>
using namespace std;
int N, M;
int mx=-1;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void bfs(vector<vector<int>> &v, pair<int, int> s){
    queue<pair<int, int>> q;
    q.push(s);
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx <N && ny>=0 && ny<M){
                if(v[nx][ny] == 0){
                    v[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void check(const vector<vector<int>> &v){
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j]==0)
                res++;
        }
    }
    if(res>mx)
        mx = res;
    
}

int main(){
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M));
    vector<pair<int, int>> start;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                start.push_back({i,j});
            }
        }
    }
    for(int i=0;i<N*M-2;i++){
        if(graph[i/M][i%M] != 0)
            continue;
        for(int j=i+1;j<N*M-1;j++){
            if(graph[j/M][j%M] != 0)
                continue;
            for(int k=j+1;k<N*M;k++){
                if(graph[k/M][k%M] != 0)
                    continue;
                vector<vector<int>> tmp = graph;
                tmp[i/M][i%M]=1;
                tmp[j/M][j%M]=1;
                tmp[k/M][k%M]=1;
                for(int l=0;l<start.size();l++)
                    bfs(tmp, start[l]);
                check(tmp);
            }
        }
    }
    cout << mx;

    return 0;
}