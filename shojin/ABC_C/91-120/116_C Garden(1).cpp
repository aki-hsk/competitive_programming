#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i=0; i<N; i++) cin >> h[i];

    int ans = 0, active = 0;
    for(int i=0; i<N; i++) {
        if(active >= h[i]) {
            active = h[i];
        } else {
            ans += h[i] - active;
            active = h[i];
        }
    }
    cout << ans << endl;
}