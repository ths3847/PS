#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        string opers;
        cin >> opers;
        int len;
        cin >> len;
        string tmp;
        cin >> tmp;
        string token;
        deque<int> x;
        if(tmp != "[]"){
            tmp = tmp.substr(1,tmp.size()-1);
            stringstream ss(tmp);
            while(getline(ss, token, ','))
                x.push_back(stoi(token));
        }
        int r=0;
        bool error =false;
        for(int i=0;i<opers.size();i++){
            if(opers[i] == 'R') r^=1;
            else{
                if(x.size()==0){
                    cout << "error" << "\n";
                    error = true;
                }
                if(r==0)
                    x.pop_front();
                else
                    x.pop_back();
            }
        }
        if(error) continue;
        if(x.size()==0) cout << "[]" << "\n";
        else{
            cout << "[";
            string str = "";
            if(r==0){
                while(x.size()){
                    str+=to_string(x.front());
                    str+=",";
                    x.pop_front();
                }
            }
            else{
                while(x.size()){
                    str+=to_string(x.back());
                    str+=",";
                    x.pop_back();
                }
            }
            str = str.substr(0,str.size()-1);
            cout << str;
            cout << "]" << "\n";
        }
    }
}