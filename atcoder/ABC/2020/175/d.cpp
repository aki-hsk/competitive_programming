#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll N, K;
    cin >> N >> K;
    ll score = 0;

    vector<ll> P(N), C(N);
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> C[i];


    for(int i=0;i<K;i++) {
        ll next = i;
        score += C[P[next]];
        next = P[i];
    }
}