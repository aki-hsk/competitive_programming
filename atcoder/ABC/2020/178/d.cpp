#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll mod = 1e9+7;

int main(){
    ll S;
    cin >> S;
    vector<ll> A(S+1);
    A[0] = 1;
    for(int i=1; i<=S; i++) {
        for(int j=0; j<=i-3; j++) {
            A[i] += A[j];
            A[i] %= mod;
        }
    }
    cout << A[S] << endl;
}