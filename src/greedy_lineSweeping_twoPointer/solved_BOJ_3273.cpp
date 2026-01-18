#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,x;
    vector<int> a;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> x;
    sort(a.begin(), a.end());
    int s(0),e(N-1);
    int res=0;
    while(s<e){
        int c = a[s]+a[e];
        if(c==x){
            res++;
            s++;
        }
        else if(c<x)
            s++;
        else if(c>x)
            e--;
    }
    cout << res;
}