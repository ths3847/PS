#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
map<pair<int,int>, int> m;
queue<pair<int, int>> q;
void enqueue(int x, int y, int n){
    if(m[{x,y}])
        return;
    m[{x,y}] = n+1;
    q.push({x,y});
}
void bfs(){
    m[{0,0}]=1;
    q.push({0,0});
    while(q.size()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        enqueue(a,y,m[{x,y}]);
        enqueue(0,y,m[{x,y}]);
        //A->B
        enqueue(max(0, x+y-b),min(b, x+y),m[{x,y}]);
        enqueue(x,b,m[{x,y}]);
        enqueue(x,0,m[{x,y}]);
        //B->A
        enqueue(min(a, x+y), max(0,x+y-a),m[{x,y}]);
    }
    if(m[{c,d}]) cout <<  (m[{c,d}]-1);
    else cout << -1;
}
int main(){
    cin >> a >> b >> c >> d;
    bfs();
    return 0;
}