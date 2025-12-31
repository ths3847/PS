#include <bits/stdc++.h>
using namespace std;
int N,K;
int main(){
    cin >> N >> K;
    int res=0;
    vector<int> visited(100001);
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while(q.size()){
        int x;
        x = q.front();
        q.pop();
        if(x==K){
            res++;
            continue;
        }
        for(int i=0;i<3;i++){
            int nx;
            switch(i){
                case 0:
                    nx=x-1;
                    break;
                case 1:
                    nx=x+1;
                    break;
                case 2:
                    nx=x*2;
                    break;
            }
            if(nx<0 || nx > 100000) continue;

            if(visited[nx]==0){ 
                visited[nx] = visited[x]+1;
                q.push(nx);
            }
            else if(visited[nx]==visited[x]+1)
                q.push(nx); //최적의 경로 경우의 수 모두 구하기 위해 추가
        }
    }
    cout << visited[K]-1 << endl;
    cout << res;
    return 0;
}