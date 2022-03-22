#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    // とりあえず全部配列に入れてソート
    sort(v.begin(), v.end());

    // 2つ連続した値があれば保存
    ll l = 0, s = 0;
    for(int i=0; i<N-1; i++) {
        if(v[i] == v[i+1]) {
            swap(l, s);
            l = v[i]; // 新たな値は常にlにいれる
            i++;
        }
    }
    cout << l * s << endl;
}