#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    //n: n以下の整数の組(a,b,c)
    //K: a+b, b+c, c+aが全てKの倍数であるような個数
    int n, k;
    cin >> n >> k;

    vector<ll> num(k, 0);
    for(int i=1; i<=n; i++) num[i%k]++; //num[x] = kで割ってx余る数が1以上N以下に何個あるか

    ll res = 0;
    for(int a = 0; a < k; a++) {
        int b = (k-a) % k;
        int c = (k-a) % k;
        if( (b+c) % k != 0) continue;
        res += num[a] * num[b] * num[c];
    }
    cout << res << endl;
}