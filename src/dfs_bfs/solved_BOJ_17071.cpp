#include <bits/stdc++.h>
using namespace std;
int v[2][500001];
int N,K;
int main(){
    cin >> N >> K;
    if(N==K){
        cout << 0;
        return 0;
    }
    int t(1);
    bool res=false;
    queue<int> q;
    q.push(N);
    while(q.size()){
        K+=t;
        if(K>500000)
            break;
        if(v[t%2][K]){
            res = true;
            break;
        }
        int qSize = q.size();
        for(int i=0;i<qSize;i++){
            int x = q.front();
            q.pop();
            for(int nx : {x-1, x+1, x*2}){
                if(nx < 0 || nx > 500000 || v[t%2][nx]) continue;
                v[t%2][nx] = v[(t+1)%2][x]+1;
                if(K == nx){
                    res = true;
                    break;
                }
                q.push(nx);
                if(res) break;
            }
            if(res) break;
        }
        if(res) break;
        t++;
    }
    if(res) cout << t;
    else cout << -1;
    
    return 0;
}