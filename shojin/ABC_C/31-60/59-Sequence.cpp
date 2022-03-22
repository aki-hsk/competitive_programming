#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N), S(N);
    for(int i=0; i<N; i++) cin >> a[i];
    S[0] = a[0];
    for(int i=1; i<N; i++) S[i] = S[i-1] + a[i];

    ll first_count = 0, second_count = 0, div = 0;
    vector<ll> T = S;
    // + - + - パターン
    for(int i=0; i<N; i++) {
        S[i] += div;
        if(i%2 == 0 && S[i] <= 0) {
            first_count += abs(S[i]) + 1;
            div += -S[i] + 1;
        }
        else if(i%2 == 1 && S[i] >= 0){
            first_count += abs(S[i]) + 1;
            div += -S[i] - 1;
        }
    }

    div = 0;
    // - + - + パターン
    for(int i=0; i<N; i++) {
        T[i] += div;
        if(i%2 == 0 && T[i] >= 0) {
            second_count += abs(T[i]) + 1;
            div += -T[i] - 1;
        }
        else if(i%2 == 1 && T[i] <= 0){
            second_count += abs(T[i]) + 1;
            div += -T[i] + 1;
        }
    }
    cout << min(first_count, second_count) << endl;
}