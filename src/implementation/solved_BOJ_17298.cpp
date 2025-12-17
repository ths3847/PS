#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    stack<int> s;
    vector<int> res(N, -1);
    for(int i=0;i<N;i++)
        cin >> v[i];
    for(int i=N-1;i>=0;i--){
        while(s.size()){
            int cmp = s.top();
            if(v[i] >= cmp)
                s.pop();
            else{
                s.push(v[i]);
                res[i] = cmp;
                break;
            }
        }
        if(res[i] == -1)
            s.push(v[i]);
    }
    for(int i=0;i<N;i++){
        cout << res[i];
        if(i!=N-1)
            cout << " ";
    }
    return 0;
}