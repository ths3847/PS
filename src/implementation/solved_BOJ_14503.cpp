#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M, r, c, d;
    cin >> N >> M >> r >> c >> d;
    vector<vector<int>> v(N,vector<int>(M,0));

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++)
            cin >> v[i][j];
    }
    int total = 0;
    while(1){
        if(v[r][c]==0){
            v[r][c]=-1;
            total++;
            continue;
        }
        bool flag=true;
        for(int i=0;i<4;i++){
            if(v[r+dx[i]][c+dy[i]] == 0){
                flag=false;
                break;
            }
        }
        if(flag){
            r += dx[(d+2)%4];
            c += dy[(d+2)%4];
            if(v[r][c]==1){
                break;
            }
            continue;
        }
        for(int i=0;i<4;i++){
            d--;
            if(d < 0)
                d=3;
            if(v[r+dx[d]][c+dy[d]]==0){
                r += dx[d];
                c += dy[d];
                break;
            }
        }
    }
    cout << total;

}