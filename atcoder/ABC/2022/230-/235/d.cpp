#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using mint = modint998244353;
const long long INF = 1LL << 60;
const int SINF = 1LL << 30;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll a, N;
    cin >> a >> N;

    vector<ll> dist(1000005, -1);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        ll cur = q.front(); q.pop();
        ll next1 = cur * a;
        if(to_string(N).size() >= to_string(next1).size()) {
            if(dist[next1] == -1) {
                dist[next1] = dist[cur] + 1;
                q.push(next1);
            }
        }
        if(cur < 10 || cur % 10 == 0) continue;
        string s = to_string(cur);
        int m = s.size();
        ll next2 = stoll(s.back() + s.substr(0, m-1));
        if(to_string(N).size() >= to_string(next2).size()) {
            if(dist[next2] == -1) {
                dist[next2] = dist[cur] + 1;
                q.push(next2);
            }
        }
    }
    cout << dist[N] << endl;

}