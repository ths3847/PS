#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string N;
    cin >> N;
    int arr[10] = {0,};
    for(int i=0;i<N.length();i++)
        arr[N[i]-'0']++;
    arr[6] = ((arr[6]+arr[9])/2)+((arr[6]+arr[9])%2);
    arr[9] = arr[6];
    
    int result = *max_element(begin(arr), end(arr));
    cout << result;
    return 0;
}