#include<iostream>
#include<vector>
using namespace std;

// https://www.youtube.com/watch?v=h0MGG8rxrYc

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n), d(n+1) {}
    void add(int i, T x=1) {
        for(i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for(i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    // 各数について最後に出てきた場所を保存する
    vector<int> pi(n+1, -1);
    vector<vector<int>> ps(n);
    for(int i=0; i<n; i++) {
        int l = pi[a[i]];
        if(l != -1) ps[l].push_back(i);
        pi[a[i]] = i;
    }

    vector<vector<pair<int, int>>> qs(n);
    for(int qi=0; qi<q; qi++) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        qs[l].push_back({r, qi});
    }

    vector<int> ans(q);
    BIT<int> d(n);
    for(int x=n-1; x>=0; --x) {
        for(int y:ps[x]) d.add(y, 1);
        for(auto query:qs[x]) {
            int r = query.first;
            int i = query.second;
            ans[i] = (r - x + 1) - d.sum(r);
        }
    }

    for(int i=0; i<q; i++) cout << ans[i] << endl;
    return 0;
}