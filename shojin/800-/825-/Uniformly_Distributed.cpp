#include<iostream>
#include<vector>
using namespace std;

// .: v[i][0], B: v[i][1], R: v[i][2]
int v[1200][3];
const int mod = 998244353;
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s[i];

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(s[i][j] == '.') v[i+j][0]++;
            if(s[i][j] == 'R') v[i+j][1]++;
            if(s[i][j] == 'B') v[i+j][2]++;
        }
    }

    long long ans = 1;
    for(int k=0; k<h+w-1; k++) {
        if(v[k][1] > 0 && v[k][2] > 0) ans = 0;
        else if(v[k][0] > 0 && v[k][1] == 0 && v[k][2] == 0) ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
}