#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N;
bool isPrime(int n){
    if (n==1) return false;
    if (n==2 || n==3) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    cin >> N;
    if(N==1){
        cout << 0;
        return 0;
    }
    int s=0;
    int e=0;
    int sm=0;
    int res=0;
    for(int i=2;i<=N;i++)
        if(isPrime(i)) v.push_back(i);
    sm+=v[0];
    while(e<v.size()){
        if(sm<N){
            e++;
            sm+=v[e];
        }
        else if(sm>N){
            sm-=v[s];
            s++;
        }
        else{
            res++;
            e++;
            if(e==N) break;
            sm+=v[e];
        }
    }

    cout << res;
    return 0;
}