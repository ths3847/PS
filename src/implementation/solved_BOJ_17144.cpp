#include<bits/stdc++.h>
using namespace std;
int R,C,T;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    cin >> R >> C >> T;
    int total=0;
    vector<vector<int>> v(R, vector<int>(C));
    vector<int> a;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> v[i][j];
            if(v[i][j]>0) total += v[i][j];
            else if(v[i][j]==-1) a.push_back(i);
        }
    }
    for(int m=0;m<T;m++){
        vector<vector<int>> tmp;
        tmp = v;
        for(int j=0;j<R;j++){
            for(int k=0;k<C;k++){
                if(v[j][k] > 0){
                    for(int l=0;l<4;l++){
                        int nx,ny;
                        nx = j+dx[l];
                        ny = k+dy[l];
                        if(nx<0||nx>=R||ny<0||ny>=C||v[nx][ny]==-1) continue;
                        tmp[nx][ny] += v[j][k]/5;
                        tmp[j][k] -= v[j][k]/5;
                    }
                }
            }
        }
        v = tmp;
        if(a[0] != 0){
            if(v[a[0]-1][0]>0) total-=v[a[0]-1][0];
            
            for(int i=a[0]-2;i>=0;i--) v[i+1][0] = v[i][0];
            
            for(int i=1;i<C;i++) v[0][i-1] = v[0][i];
            
            for(int i=1;i<=a[0];i++) v[i-1][C-1] = v[i][C-1];
            
            for(int i=C-2;i>=1;i--) v[a[0]][i+1] = v[a[0]][i];

            v[a[0]][1]=0;
            
        }
        if(a[1] != R-1){
            if(v[a[1]+1][0]>0) total-=v[a[1]+1][0];
            
            for(int i=a[1]+2;i<R;i++) v[i-1][0] = v[i][0];
            
            for(int i=1;i<C;i++) v[R-1][i-1] = v[R-1][i];
            
            for(int i=R-2;i>=a[1];i--) v[i+1][C-1] = v[i][C-1];
            
            for(int i=C-2;i>=1;i--) v[a[1]][i+1] = v[a[1]][i];
            v[a[1]][1]=0;
        }
    }
    cout << total;
    return 0;
}