#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int res =0;
    cin >> N;
    for(int i=0;i<=7;i++){
        if(N&(1<<i))
            res++;
    }
    cout << res;
}