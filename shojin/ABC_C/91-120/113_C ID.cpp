#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int N, M;
ll P[100000], Y[100000];
vector<vector<ll>> yd;

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> P[i] >> Y[i];
        yd[P[i]].push_back(Y[i]); //県をキーとして年数を入れた配列を作る
    }

    for(int i=0; i<N; i++) {
        //年数順にソート
        sort(yd[i+1].begin(), yd[i+1].end());
    }

    for(int i=0; i<M; i++) {
        ll ans = (ll)(P[i])*1000000+(ll)(lower_bound(yd[P[i]].begin(), yd[P[i]].end(), Y[i])-yd[P[i]].begin())+1;
        //12桁0埋めして出力
        cout << setfill('0') << right << setw(12) << ans << endl;
    }

}