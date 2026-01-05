#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int res=0;
    int mx=0;
    for(int i=1;i<=20;i++)
        mx |= (1<<i);
    
    for(int i=0;i<N;i++){
       string oper;
       int p=0;
       cin >> oper;
       if(oper!="all" && oper!="empty") cin >> p;
       if(oper=="add"){
        res |= (1<<p); 
       }
       else if(oper=="remove"){
        res &= (~(1<<p));
       }
       else if(oper=="check"){
        if(res&(1<<p))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
       }
       else if(oper=="toggle"){
            res ^= (1<<p);
       }
       else if(oper=="all"){
            res = mx;
       }
       else if(oper=="empty"){
            res = 0;
       }
       
    }
}