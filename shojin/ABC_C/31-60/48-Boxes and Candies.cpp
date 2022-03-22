#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];
    ll count = 0;
    for(int i=0; i<N-1; i++) {
        if(a[i]+a[i+1] > x) {
            ll div = a[i]+a[i+1] - x;
            a[i+1] -= div;
            count += div;
            // a[i+1]が0より小さくならないようにする
            // a[i+1] < 0となる時はa[i]からあめを食べている
            a[i+1] = max(0, a[i+1]);
        }
    }
    cout << count << endl;
}