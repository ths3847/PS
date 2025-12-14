#include <bits/stdc++.h>
using namespace std;

void print(int n){
    string str;
    if(n/60 < 10)
        str += "0";
    str += to_string(n/60);
    str += ":";
    if(n%60 < 10)
        str += "0";
    str += to_string(n%60);
    cout << str << '\n';
}

int main(){
    int N;
    cin >> N;
    int cnt1(0);
    int cnt2(0);
    int s1=-1;
    int s2=-1;
    int res1(0);
    int res2(0);
    int w=0;
    for(int i=0;i<N;i++){
        int g;
        int t=0;
        string str;
        cin >> g;
        cin >> str;
        t += stoi(str.substr(0, str.find(":")))*60;
        t += stoi(str.substr(str.find(":")+1, str.size()));
        if(g==1)
            cnt1++;
        else
            cnt2++;
        
        if(cnt1 > cnt2){
            if(s1==-1)
                s1 = t;
        }
        else if(cnt1 < cnt2){
            if(s2==-1)
                s2 = t;
        }
        else{
            if(s1!=-1){
                res1 += t-s1;
                s1 = -1;
            }
            else if(s2!=-1){
                res2 += t-s2;
                s2 = -1;
            }
        }
    }
    if(cnt1>cnt2){
        res1 += 48*60 - s1;
    }
    else if(cnt2>cnt1){
        res2 += 48*60 - s2;
    }
    print(res1);
    print(res2);

    return 0;
}