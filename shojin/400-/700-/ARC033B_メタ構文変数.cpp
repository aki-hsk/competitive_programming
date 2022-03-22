#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    set<int> uni, in;
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    sort(all(a));
    sort(all(b));
    // 和集合
    set_union(all(a), all(b), inserter(uni, end(uni)));

    // 積集合
    set_intersection(all(a), all(b), inserter(in, end(in)));

    double x = uni.size(), y = in.size();
    printf("%10.10f", y / x);
}