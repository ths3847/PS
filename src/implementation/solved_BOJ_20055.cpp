#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> v(2*N);
    vector<int> r_pos(2*N);
    queue<int> q;
    for(int i=0;i<2*N;i++)
        cin >> v[i];
    int start=0;
    int end;
    int lastidx = 2*N-1;
    int total=0;
    int nZero=0;
    int m = 2*N;
    while(1)
    {

        total++;
        // step1
        start--;
        if(start<0) start = lastidx;
        end = (start+(N-1))%m;
        if(r_pos[end]){
            r_pos[end] = 0;
            q.pop();
        }

        // step2
        int s = q.size();
        for(int i=0;i<s;i++){
            int o = q.front();
            int a = (o+1)%m;
            q.pop();
            if(r_pos[a]==0 && v[a]>0){

                r_pos[o]=0;
                v[a]--;
                if(v[a]==0)
                    nZero++;
                
                if(a!=end){
                    r_pos[a]=1;
                    q.push(a);
                }
            }
            else
                q.push(o);
        }
        // step3
        if(v[start]>0){
            q.push(start);
            r_pos[start]=1;
            v[start]--;
            if(v[start]==0)
                nZero++;
        }
 
        if(nZero>=K)
            break;
    }
    cout << total;
    return 0;
}