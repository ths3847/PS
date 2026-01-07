#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    vector<string> v = {"pi", "ka", "chu"};
    
    for(int i=0;i<str.size();){
        bool check = false;
        for(int j=0;j<3;j++){
            if(v[j].size() > str.size()-i)
                break;
            if(str.compare(i,v[j].size(), v[j])==0){
                i+=v[j].size();
                check = true;
                break;
            }
        }
        if(!check){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}