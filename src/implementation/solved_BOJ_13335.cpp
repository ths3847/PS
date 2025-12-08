#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, w, L;
    int result = 0;
    int total = 0;
    vector<vector<int>> v;
    cin >> n >> w >> L;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        vector<int> vTmp;
        vTmp.push_back(tmp);
        vTmp.push_back(0);
        v.push_back(vTmp);
    } 
    for(int i=0;i<(n+1)*w;i++){
        result++;
        int curL=0;
        
        for(int j=0;j<n;j++){
            if(v[j][1]==0){
                curL+=v[j][0];
                if(L >= curL){
                    v[j][1]++;
                    total++;
                }
                break;
            }
            else if(v[j][1] <= w){
                if(v[j][1]< w)
                    curL += v[j][0];
                v[j][1]++;
                total++;
            }
        }
        if(total == n*(w+1))
            break;
    }
    cout << result;
    return 0;
}