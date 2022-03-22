#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    for(int i=0; i<N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll ans = 0;

    for(int i=0; i<N; i++) {
        //lower_bound: 指定したvalue以上の最初の要素の位置をイテレータで返す
        ll pre = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        //upper_bound: 指定したvalueより大きい最初の要素の位置をイテレータで返す
        ll over = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += pre * over;
    }
    cout << ans << endl;
}