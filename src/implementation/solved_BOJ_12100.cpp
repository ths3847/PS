#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> a;
int N;
void rec(vector<int> n){
    if(n.size()==5){
        a.push_back(n);
        return;
    }
    for(int i=0;i<4;i++){
        n.push_back(i);
        rec(n);
        n.pop_back();
    }
}

void rotate(int n){
    
    for(int t=0;t<n;t++){
        vector<vector<int>> tmp=v;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                v[i][j] = tmp[N-1-j][i];
        }
    }
}


int main(){
    cin >> N;
    int mx=-1;
    for(int i=0;i<N;i++){
        vector<int> vtmp;
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            vtmp.push_back(tmp);
        }
        v.push_back(vtmp);
    }
    vector<int> tt;
    rec(tt);
    for(int i=0;i<a.size();i++){
        vector<vector<int>> backup = v;

        for(int j=0;j<5;j++){
            rotate(a[i][j]);
#if 1
            for(int k=0;k<N;k++){
                vector<int> tmp;
                int c=0;
                for(int l=0;l<N;l++){
                    if(v[k][l]==0)
                        continue;
                    if(c==0){
                        c = 1;
                        tmp.push_back(v[k][l]);
                    }
                    else{
                        if(tmp[tmp.size()-1] == v[k][l]){
                            tmp[tmp.size()-1] *= 2;
                            c=0;
                        }
                        else{
                            tmp.push_back(v[k][l]);
                        }
                    }
                    mx = max(mx, tmp[tmp.size()-1]);
                }
                for(int i = tmp.size(); i<N;i++) tmp.push_back(0);
                v[k]=tmp;
            }
#endif
        }  
        v = backup;
    }
    cout << mx;
    return 0;
}