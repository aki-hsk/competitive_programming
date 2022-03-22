#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll mod=1000000007;

int main(){
    int N, count = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        if(a == b) count++;
        if(a != b) count = 0;
        if(count >= 3)  {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}