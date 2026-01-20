#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> S;
int mn=987654321;

void check(int bit){
    int n1(0), n2(0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(bit&(1<<i) && bit&(1<<j)){
                n1+=S[i][j];
            }
            else if(!(bit&(1<<i)) && !(bit&(1<<j))){
                n2+=S[i][j];
            }
        }
    }
    mn = min(mn,abs(n1-n2));
}

void getList(int n, int idx, int bit){
    if(n==N/2){
        check(bit);
        return;
    }
    for(int i=idx;i<N;i++){
        bit |= (1<<i);
        getList(n+1, i+1, bit);
        bit &= ~(1<<i);
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        vector<int> vtmp;
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            vtmp.push_back(tmp);
        }
        S.push_back(vtmp);
    }
    getList(0,0,0);
    cout << mn;
    return 0;
}