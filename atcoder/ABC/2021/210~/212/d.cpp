#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using P = pair<long long, long long>;

int main() {
    int n;
    cin >> n;
    priority_queue<P, vector<P>, greater<P>> q;

    ll sum = 0;
    vector<ll> ans;
    rep(i, n) {
        int m;
        cin >> m;
        if(m == 1) {
            ll x;
            cin >> x;
            q.push({x-sum, sum});
        }
        else if(m == 2) {
            ll x;
            cin >> x;
            sum += x;
        }
        else {
            ll x = q.top().first;
            ll y = q.top().second;
            q.pop();
            ans.push_back(x+sum);
        }
    }
    for(auto a:ans) cout << a << endl;
}