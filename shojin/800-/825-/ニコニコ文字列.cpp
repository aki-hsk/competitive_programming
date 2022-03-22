#include<iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll niko_cnt = 0;
    bool niko = false;
    ll ans = 0;
    for(int i=0; i<n-1; i++) {
        if(s[i] == '2' && s[i+1] == '5') {
            niko_cnt++;
            niko = true;
            i++;
        }
        else {
            ans += niko_cnt*(niko_cnt + 1)/2;
            niko_cnt = 0;
            niko = false;
        }
    }
    ans += niko_cnt*(niko_cnt + 1)/2;
    cout << ans << endl;
}