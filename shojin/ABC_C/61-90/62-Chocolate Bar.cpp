#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    ll H, W;
    cin >> H >> W;

   ll ans = H * W;
    ll s[3];
    for(int i=0; i<2; i++) {
        for(ll h = 1; h < H; h++) {
            //s[i], s[2]を縦に割る
            s[0] = h * W;
            s[1] = (H - h) * (W / 2);
            s[2] = H * W - (s[0] + s[1]);
            sort(s, s+3);
            ans = min(ans, s[2] - s[0]);

            //s[1], s[2]を横に割る
            s[0] = h * W;
            s[1] = ((H - h)/2) * W;
            s[2] = H * W - (s[0] + s[1]);
            sort(s, s + 3);
            ans = min(ans, s[2] - s[0]);
        }
        swap(H, W);
    }
    cout << ans << endl;
    return 0;
}