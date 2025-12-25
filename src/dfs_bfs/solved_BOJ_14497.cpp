#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, M;
int gx1, gy1, gx2, gy2;
int res=0;
vector<vector<char>> v;
vector<vector<int>> visited;

bool bfs(){
    res++;
    queue<pair<int, int>> q;
    q.push({gx1,gy1});
    while(q.size()){
        int x,y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M && visited[nx][ny]==0){
                visited[nx][ny] = 1;
                if(v[nx][ny] == '1')
                    v[nx][ny] = '0';
                else if(v[nx][ny]== '0')
                    q.push({nx,ny});
                else if(v[nx][ny] == '#')
                    return true;
            }
        }
    }
    return false;
}


int main(){
    cin >> N >> M;
    cin >> gx1 >> gy1 >> gx2 >> gy2;
    
    gx1--; gy1--; gx2--; gy2--;
    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        vector<char> vtmp;
        for(int j=0;j<M;j++){
            vtmp.push_back(tmp[j]);
        }
        v.push_back(vtmp);
        
        vector<int> itmp(M);
        visited.push_back(itmp);
    }
    while(!bfs()){
        for(auto &row : visited)
            fill(row.begin(), row.end(), 0);
    }
    cout << res;
    return 0;
}