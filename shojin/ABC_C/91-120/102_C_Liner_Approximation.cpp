#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N, total;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i], B[i] = A[i] - i - 1;

    //medium(中央値を取る)
    sort(B.begin(), B.end());
    ll x = B[N/2];

    ll res = 0;
    for(int i=0; i<N; i++) {
        res += abs(x - B[i]); // |A| = max(A, -A)
    }
    cout << res << endl;
}