#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> x;
ll man(vector<ll> x) {
    ll res = 0;
    for(int i=0; i<x.size(); i++) {
        res += abs(x[i]);
    }
    return res;
}

double yu(vector<ll> x) {
    ll res = 0;
    for(int i=0; i<x.size(); i++) {
        res += pow(x[i], 2);
    }
    return pow(res, 0.5);
}

ll che(vector<ll> x) {
    ll res = 0;
    for(int i=0; i<x.size(); i++) {
        chmax(res, abs(x[i]));
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    x.resize(N);
    for(int i=0; i<N; i++) cin >> x[i];
    cout <<fixed << setprecision(16) << man(x) << endl;
    cout <<fixed << setprecision(16) << yu(x) << endl;
    cout <<fixed << setprecision(16) << che(x) << endl;

}