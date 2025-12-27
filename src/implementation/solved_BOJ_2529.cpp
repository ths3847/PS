#include <bits/stdc++.h>
using namespace std;
vector<char> v;
vector<int> asc = {0,1,2,3,4,5,6,7,8,9};
vector<int> dsc = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0};
int N;



bool check(vector<int> &a){
    for(int i=0;i<N;i++){
        switch(v[i]){
            case '>':
                if(a[i]<a[i+1]) return false;
                break;
            case '<':
                if(a[i]>a[i+1]) return false;
                break;
        }
    }
    return true;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> va;
    do{
        vector<int> empty;
        va.swap(empty);
        for(int i=0;i<=N;i++) va.push_back(dsc[i]*-1);
        if(check(va)) break;
    }while(next_permutation(dsc.begin(), dsc.end()));
    for(int i : va) cout << i;
    cout << endl;

    do{
        vector<int> empty;
        va.swap(empty);
        for(int i=0;i<=N;i++) va.push_back(asc[i]);
        if(check(va)) break;
    }while(next_permutation(asc.begin(), asc.end()));
    for(int i : va) cout << i;


}