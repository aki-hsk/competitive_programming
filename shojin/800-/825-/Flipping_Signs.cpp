#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> a(n);
    ll n_cnt = 0;
    ll m = (1<<30);
    rep(i, n) {
        cin >> a[i];
        if (a[i] < 0) {
            res += -a[i];
            n_cnt++;
        }
        else res += a[i];
        if(abs(a[i]) < abs(m)) m = abs(a[i]);
    }

    if (n_cnt % 2 == 1) res -= 2 * m;
    cout << res << endl;
}