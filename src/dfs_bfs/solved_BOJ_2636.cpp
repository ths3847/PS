#include <bits/stdc++.h>
using namespace std;
int N, M, mx, cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(vector<vector<int>> &v, vector<vector<int>> &visit, pair<int ,int> s)
{
    int res = 0;
    cnt = 0;
    queue<pair<int, int>> q;
    q.push(s);
    visit[s.first][s.second] = 1;
    res++;
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && visit[nx][ny] == 0 && v[nx][ny]!=-1){
                if(v[nx][ny] == 0){
                    visit[nx][ny] = 1;
                    q.push({nx,ny});
                    res++;
                }
                else if(v[nx][ny]==1){
                    cnt++;
                    v[nx][ny] = -1;
                }
            }
        }
    }
    return res;
}

void convert(vector<vector<int>> &v){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j] == -1)
                v[i][j] =0;
        }
    }
}

int main(){

    cin >> N >> M;
    int res=0;
    int prev;
    int total=0;
    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<int>> visit(N, vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> v[i][j];
            total += v[i][j];
        }
    }
    if(total == 0){
        cout << 0 << endl << 0;
        return 0;
    }
    
    
    while(1){
        
        vector<vector<int>> tmpv = visit;
        res = bfs(v, tmpv ,{0,0});
        convert(v);
        if(res == N*M)
            break;
        prev = cnt;
        mx++;
    }
    cout << mx << endl;
    cout << prev;

    return 0;
}