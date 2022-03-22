#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vector<pair<int, int>> vp(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        vp[i] = make_pair(b, a);
    }
    sort(vp.rbegin(), vp.rend());

    int a_index = 0, vp_index = 0;
    ll sum = 0;
    rep(i, n) {
        if(vp_index >= vp.size() || a[a_index] >= vp[vp_index].first) {
            sum += a[a_index];
            a_index++;
        }
        else if(vp_index < vp.size() && vp[vp_index].first > a[a_index]) {
            sum += vp[vp_index].first;
            vp[vp_index].second--;
            if(vp[vp_index].second == 0) vp_index++;
        }
    }
    cout << sum << endl;
}