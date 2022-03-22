#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(int i=0; i<n; i++)

int main() {
    int n, k;
    cin >> n >> k;
    // 正と負に入力を分ける
    vector<int> a(n);
    vector<int> s, t;
    rep(i,n) {
        cin >> a[i];
        if(a[i] < 0) t.push_back(a[i]);
        else s.push_back(a[i]);
    }

    int S = s.size();
    int T = t.size();
    // 正にすることができるか？
    bool ok = false;
    if(S > 0) {
        if(n == k) ok = (T%2 == 0);
        else ok = true;
    }
    else {
        ok = (k % 2 == 0);
    }

    mint ans = 1;
    if(!ok) {
        sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
        rep(i, k) ans *= a[i];
    }
    else {
        sort(s.begin(), s.end());
        sort(t.rbegin(), t.rend());
        if(k % 2 == 1) {
            ans *= s.back();
            s.pop_back();
        }
        vector<long long> p;
        while(s.size() >= 2) {
            long long x = s.back(); s.pop_back();
            x *= s.back(); s.pop_back();
            p.push_back(x);
        }
        while(t.size() >= 2) {
            long long x = t.back(); t.pop_back();
            x *= t.back(); t.pop_back();
            p.push_back(x);
        }
        sort(p.rbegin(), p.rend());
        rep(i, k/2) ans *= p[i];
    }
    cout << ans.val() << endl;
    return 0;
}