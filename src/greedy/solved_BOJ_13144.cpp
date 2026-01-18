#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    vector<int> visited(100001);
    long long res=0;
    int s=0;
    int e=0;
    while(e<N){
        if(visited[v[e]]){
            res += e-s;
            visited[v[s]]=0;
            s++;
        }
        else{
            visited[v[e]] = 1;
            e++;
        }
    }
    long long n = e-s;
    res += (n*(n+1))/2;
    cout << res;
    return 0;
}