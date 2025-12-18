#include<bits/stdc++.h>
using namespace std;
vector<int> v(100001);
vector<int> p(100001, -1);
int N, M;
int main(){
    vector<int> res;
    cin >> N >> M;
    queue<int> q;
    q.push(N);
    p[N] = 0;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0){
                if(x-1 >= 0 && v[x-1] == 0){
                    v[x-1] = v[x]+1;
                    q.push(x-1);
                    p[x-1] = x;
                }
            }
            else if(i==1){
                if(x+1 <= M && v[x+1] == 0){
                    v[x+1] = v[x]+1;
                    q.push(x+1);
                    p[x+1] = x;
                }
            }
            else{
                if(x*2 <= 100001 && v[x*2] == 0){
                    v[x*2] = v[x]+1;
                    q.push(x*2);
                    p[2*x] = x;
                }
            }
        }
    }

    if(N == M){
        cout << 0 << endl;
        cout << 0;
        return 0;
    }

    cout << v[M] << endl;
    int tmp = M;
    while(tmp != N){
        res.push_back(tmp);
        tmp = p[tmp];
    }
    cout << N << " ";
    for(int i = res.size()-1; i>=0;i--){
        cout << res[i];
        if( i!=0) cout << " ";
    }
    return 0;
}