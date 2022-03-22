#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> p_que;
    deque<int> d_que;
    rep(k, q) {
        int c;
        cin >> c;
        if(c == 1) {
            int x;
            cin >> x;
            d_que.push_back(x);
        }
        else if(c == 2) {
            if(!p_que.empty()) {
                cout << p_que.top() << endl;
                p_que.pop();
                continue;
            }
            cout << d_que.front() << endl;
            d_que.pop_front();
        }
        else {
            for(auto d:d_que) p_que.push(d);
            d_que.clear();
        }
    }
}