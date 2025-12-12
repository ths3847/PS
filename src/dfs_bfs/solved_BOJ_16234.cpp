#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, L, R;

int bfs(vector<vector<int>> &graph, vector<vector<int>> &visit, stack<pair<int, int>> &idx, int x, int y){
    int total =0;
    queue<pair<int,int>> q;
    q.push({x,y});
    idx.push({x,y});
    visit[x][y] = 1;
    total += graph[x][y];
    while(q.size()){
        auto cur = q.front();
        q.pop();
        int cx, cy;
        cx = cur.first;
        cy = cur.second;
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if((nx>=0)&&(nx<N)&&(ny>=0)&&(ny<N)){
                int diff = abs(graph[cx][cy]-graph[nx][ny]);
                if(visit[nx][ny]==0 && diff>=L && diff<=R){
                    visit[nx][ny]=1;
                    idx.push({nx,ny});
                    total+=graph[nx][ny];
                    q.push({nx,ny});
                }
            }
        }
    }
    return total;
}

int main()
{
    int result = 0;
    cin >> N >> L >> R;
    vector<vector<int>> graph(N, vector<int>(N));
    vector<vector<int>> visit(N, vector<int>(N));

    stack<pair<int,int>> idx;
    queue<pair<int, int>> q;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> graph[i][j];
    }

    while(1)
    {
        bool stop = true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int total;
                if(visit[i][j] == 0){
                    total = bfs(graph,visit,idx, i, j);
                    if(total != graph[i][j] ){
                        stop = false;
                        total = total/idx.size();
                        while(idx.size()){
                            auto cur = idx.top();
                            idx.pop();
                            graph[cur.first][cur.second] = total;
                        }
                    }
                    else{
                        idx.pop();
                    }
                }
            }
        }
        if(stop)
            break;
        result++;
        for(auto &row : visit) fill(row.begin(), row.end(), 0);
    }
    cout << result;
    return 0;
}