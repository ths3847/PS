#include <bits/stdc++.h>
using namespace std;
deque<int> dq[4];

void rotate(int x, int d){
    if(d==1){
        int tmp = dq[x].back();
        dq[x].push_front(tmp);
        dq[x].pop_back();
    }
    else{
        int tmp = dq[x].front();
        dq[x].push_back(tmp);
        dq[x].pop_front();
    }
}

queue<pair<int,int>> bfs(int x, int d){
    queue<pair<int, int>> q;
    queue<pair<int,int>> ret;
    vector<int> visited(4);
    q.push({x,d});
    ret.push({x,d});
    visited[x] = 1;
    while(q.size()){
        int cx, cd;
        tie(cx, cd) = q.front();
        q.pop();
        if(cx-1>=0 && visited[cx-1]!=1){
            visited[cx-1]=1;
            if(dq[cx][6]!=dq[cx-1][2]){
                ret.push({cx-1,cd*-1});
                q.push({cx-1,cd*-1});
            }
        }
        if(cx+1<=3&&visited[cx+1]!=1){
            visited[cx+1]=1;
            if(dq[cx][2]!=dq[cx+1][6]){
                ret.push({cx+1,cd*-1});
                q.push({cx+1,cd*-1});
            }
        }
    }
    return ret;
}
int main(){
    
    for(int i=0;i<4;i++){
        string str;
        cin >> str;
        for(int j=0;j<8;j++)
            dq[i].push_back(str[j]-'0');
    }
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x,d;
        cin >> x >> d;
        queue<pair<int, int>> tmp;
        tmp = bfs(x-1,d);
        while(tmp.size()){
            int a,b;
            tie(a,b) = tmp.front();
            tmp.pop();
            rotate(a,b);
        }
    }
    int res=0;
    int tmp=1;
    if(dq[0][0])
        res+=tmp;
    for(int i=1;i<4;i++){
        tmp*=2;
        if(dq[i][0])
            res += tmp;
    }
    cout << res;
    return 0;
}
