#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    vector<vector<int>> oper;
    v.push_back(-1); //인덱스, 스위치 번호 통일
    int N, m,tmp;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        vector<int> tmpv;
        cin >> tmp;
        tmpv.push_back(tmp);
        cin >> tmp;
        tmpv.push_back(tmp);
        oper.push_back(tmpv);
    }
    for(int i=0;i<m;i++){
        if(oper[i][0]==1){
            for(int j=oper[i][1];j<=N;j+=oper[i][1])
                v[j] ^= 1;
        }
        else{
            v[oper[i][1]] ^= 1;
            for(int j=1;j<=N/2;j++){
                if(oper[i][1]-j >=1 && oper[i][1]+j<=N){
                    if(v[oper[i][1]-j]==v[oper[i][1]+j]){
                        v[oper[i][1]-j] ^= 1;
                        v[oper[i][1]+j] ^= 1;
                    }
                    else
                        break;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(i==N)
            cout << v[i];
        else if(i%20==0)
            cout << v[i] << endl;
        else
            cout << v[i] << " ";
    }
    return 0;
}