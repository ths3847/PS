#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(10001);
    int N;
    cin >> N;
    int res = 665;
    for(int i=1;i<10001;i++){
        string tmp;
        while(1){
            res++;
            tmp = to_string(res);
            if(tmp.find("666") != string::npos){
                v[i] = res;
                break;
            }
        }
    }
    cout << v[N];
    return 0;
}