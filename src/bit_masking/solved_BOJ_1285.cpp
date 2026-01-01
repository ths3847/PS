#include <bits/stdc++.h>
using namespace std;
int N;
int mn=10000000;
vector<int> v;
void go(int here){
    if(here==N){
        int res=0;
        for(int i=0;i<N;i++){
            int tmp = 0;
            for(int j=0;j<N;j++){
                if(v[j]&(1<<i))
                    tmp++;
            }
            res += min(tmp, N-tmp);
        }
        if(res<mn) mn = res;
        return;
    }
    go(here+1);
    v[here] = ~v[here];
    go(here+1);
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        v.push_back(0);
        string str;
        cin >> str;
        int tmp=1;
        for(int j=0;j<N;j++){
            if(str[j]=='T') v[i] += tmp;
            tmp*=2;
        }
    }
    go(0);
    cout << mn;
}