#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n2(0);
        int n5(0);
        int tmp;
        cin >> tmp;
            for(int j=2;j<=tmp;j*=2)
                n2+=tmp/j;
            for(int j=5;j<=tmp;j*=5)
                n5+=tmp/j;
        cout << min(n2,n5) << '\n';
    }
    return 0;
}