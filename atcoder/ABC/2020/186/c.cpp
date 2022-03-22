#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool seven_10(int x) {
    while(x) {
        int y = x % 10;
        if(y == 7) return true;
        x /= 10;
    }
    return false;
}

bool seven_8(int x) {
    while(x) {
        int y = x % 8;
        if(y == 7) return true;
        x /= 8;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    set<int> include_seven;

    for(int i=7; i<=N; i++) {
        if(seven_10(i)) include_seven.insert(i);
        else if(seven_8(i)) include_seven.insert(i);
    }
    cout << N - include_seven.size() << endl;
}