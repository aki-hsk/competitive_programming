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

    vector<int> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i] >> b[i];
    vector<int> c(N), d(N);
    for(int i=0; i<N; i++) cin >> c[i] >> d[i];

    vector<pair<int, int>> ab(N);
    for(int i=0; i<N; i++) ab[i] = make_pair(a[i], b[i]);

    vector<pair<int, int>> cd(N);
    for(int i=0; i<N; i++) cd[i] = make_pair(c[i], d[i]);

    // x軸順でソート
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    vector<int> used(N, false);
    int ans = 0;
    for(int i=0; i<N; i++) {
        pair<int, int> B = cd[i];
        int index = -1;
        int maxV = INT_MIN;
        for(int j=0; j<N; j++) {
            if(!used[j] && ab[j].second < B.second && ab[j].first < B.first && maxV < ab[j].second) {
                index = j;
                chmax(maxV, ab[j].second);
            }
        }
        if(index != -1) {
            ans++;
            used[index] = true;
        }
    }
    cout << ans << endl;
    return 0;
}