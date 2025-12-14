#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vv;
int mx=-1;
int N;

void check(vector<vector<int>> v, vector<int> idxv){
    unsigned int mask = ~((1u << 3) -1);
    int idx=0;
    int res=0;
    for(int i=0;i<N;i++){
        int out =0;
        unsigned int x = 0b00000000;
        while(out!=3){
            int oper = v[i][idxv[idx]];
            if(oper==0)
                out++;
            else if(oper==1){
                x <<= 1;
                x |= 0b00000001;
                res += __builtin_popcount(x&mask);
                x &= 0b00000111;
            }
            else if(oper==2){
                x <<=2;
                x |= 0b00000010;
                res += __builtin_popcount(x&mask);
                x &= 0b00000111;
            }
            else if(oper==3){
                x <<=3;
                x |= 0b00000100;
                res += __builtin_popcount(x&mask);
                x &= 0b00000111;
            }
            else{
                x <<=4;
                res += __builtin_popcount(x&mask);
                res++;
                x = 0b00000000;         
            }
            idx++;
            idx%=9;
        }
    }
    if(res>mx)
        mx = res;
}

int main(){
    cin >> N;
    vector<vector<int>> v(N, vector<int>(9));

    for(int i=0;i<N;i++){
        for(int j=0;j<9;j++)
            cin >> v[i][j];
    }

    vector<int> tmpv;
    for(int i=0;i<9;i++) tmpv.push_back(i);

    do{
        vv.push_back(tmpv);
    }
    while(next_permutation(tmpv.begin()+1, tmpv.end()));

    for(int i=0;i<vv.size();i++){
        vv[i].insert(vv[i].begin()+4, vv[i][0]);
        vv[i].erase(vv[i].begin());
        check(v, vv[i]);
    }
    
    cout << mx;
    return 0;
}