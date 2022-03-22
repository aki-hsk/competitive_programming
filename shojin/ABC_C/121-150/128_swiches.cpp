#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    // N:スイッチの数
    // M:電球の数
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for(int i=0; i<M; i++) {
        int k;
        cin >> k;
        for(int j=0; j<k; j++) {
            int s;
            cin >> s;
            s--;    //デクリメントして0indexにする
            a[s] |= 1 << i;
        }
    }
    int p = 0;
    for(int i=0; i<M; i++) {
        int x;
        cin >> x;
        p |= x<<i;  //pのiビット目を1にする
    }

    int ans = 0;
    for(int s=0; s<(1<<N); s++) {
        int t = 0;
        for(int i=0; i<N; i++) {
            if(s>>i&1) {
                t ^= a[i];  //xor
            }
        }
        if(t == p) {
            ans++;
        }
    }
    cout << ans++ << endl;
}