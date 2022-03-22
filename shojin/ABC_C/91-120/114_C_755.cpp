#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int N;
int ans = 0;
int calc = 0;

void dfs(ll x, bool flag3, bool flag5, bool flag7) {
    calc++;
    if(x > N) return;
    // 3, 5, 7を全て含むならans++
    if(flag3 && flag5 && flag7) ans++;

    dfs(10 * x + 3, true, flag5, flag7);
    dfs(10 * x + 5, flag3, true, flag7);
    dfs(10 * x + 7, flag3, flag5, true);
}

int main() {
    // 入力
    cin >> N;
    dfs(0, 0, 0, 0);

    //出力
    cout << ans << endl;
    cout << calc <<endl;
}