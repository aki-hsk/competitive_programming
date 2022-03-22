#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    ll count = 0;
    for(int i=0; i<N; i++) {
        ll a, b;
        cin >> a >> b;
        count += ((b-a+1) * (2 * a + (b - a))) / 2;
    }
    cout << count << endl;
}