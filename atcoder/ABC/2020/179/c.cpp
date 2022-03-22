#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll mod=998244353;

int main(){
    ll A, B, C, N;
    cin >> N;

    ll count = 0;
    for(ll a=1; a<=N; a++) {
        ll x = (N-1)/a;
        count += x;
    }
    cout << count << endl;
}