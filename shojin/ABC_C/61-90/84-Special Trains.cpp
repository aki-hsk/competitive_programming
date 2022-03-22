#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    vector<int> C(N-1), S(N-1), F(N-1);
    for(int i=0; i<N-1; i++) cin >> C[i] >> S[i] >> F[i];

    //i:スタート地点
    for(int i=0; i<N; i++) {
        ll t = 0;
        for(int j=i; j<N-1; j++) {
            if(t < S[j]) t = S[j];
            else if(t % F[j] == 0) t = t;
            else t = t + F[j] - (t % F[j]);
            t += C[j];
        }
        cout << t << endl;
    }
}