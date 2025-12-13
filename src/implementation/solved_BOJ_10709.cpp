#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    vector<string> v;
    cin >> H >> W;
    vector<vector<int>>visit(H, vector<int>(W, -1));

    for(int i=0; i<H;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(v[i][j] == 'c')
                visit[i][j] = 0;
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(visit[i][j] == 0){
                int nj = j;
                while(1){
                    if(nj == W-1)
                        break;
                    else if(visit[i][nj+1] == 0)
                        break;
                    else{
                        visit[i][nj+1] = visit[i][nj]+1;
                    }
                    nj++;
                }
            }
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << visit[i][j];
            if(j!=W-1)
             cout << " ";
        }
        if(i!= H-1)
            cout << endl;
    }
    
    return 0;
}