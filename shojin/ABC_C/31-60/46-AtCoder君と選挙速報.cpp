#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<ll> t(N), a(N);
    for(int i=0; i<N; i++) {
        cin >> t[i] >> a[i];
    }


    ll T = 1, A = 1;
    for(int i=0; i<N; i++) {
        ll co = max((T+t[i]-1)/t[i], (A+a[i]-1)/a[i]);
        T = co * t[i];
        A = co * a[i];
    }
    cout << T + A << endl;
}