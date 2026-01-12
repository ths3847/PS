#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int h;
    int cnt;
}node;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    long long ret=0;
    stack<node> s;
    cin >> N;
    for(int i=0;i<N;i++){
        int cur;
        cin >> cur;
        int same = 1;
        while(s.size() && s.top().h < cur){
            ret+=s.top().cnt;
            s.pop();
        }
        if(s.size() &&s.top().h == cur){
            same += s.top().cnt;
            ret+=s.top().cnt;
            s.pop();
        }
        if(s.size())
            ret++;
        s.push({cur, same});
    }
    
    cout << ret;
    return 0;
}