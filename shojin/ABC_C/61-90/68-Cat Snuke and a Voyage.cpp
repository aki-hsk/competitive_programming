#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    // N:島の数, M:入力の数
    int N, M;
    cin >> N >> M;
    map<pair<int, int>, bool> m;

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        m[make_pair(a, b)] = true;
        m[make_pair(b, a)] = true;
    }

    bool flag = false;

    for(int i=2; i<N; i++) {
        if(m[make_pair(1, i)] && m[make_pair(i, N)]) flag = true;
    }
    cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}