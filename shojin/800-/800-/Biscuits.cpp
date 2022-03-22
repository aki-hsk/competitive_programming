#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    ll odd = 0, even = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i] % 2 == 0) even++;
        else if(a[i] % 2 == 1) odd++;
    }

    if(p == 0) {
        if(odd == 0) cout << (1LL << even) << endl;
        else cout << (1LL << (even + odd - 1)) << endl;
    }
    if(p == 1) {
        if(odd == 0) cout << 0 << endl;
        else cout << (1LL << (even + odd - 1)) << endl;
    }

    // aiの中に奇数の袋がある時k番目以外の選び方は2^n-1通り
    // 合計をsとすると
    // sが奇数のときkを選ぶと偶数, 選ばないと奇数
    // sが偶数のときkを選ぶと奇数, 選ばないと偶数
}