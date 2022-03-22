#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int carry = 0;
    long long res = 0;

    for(int i=0; i<n; i++) {
        int got = s[i]-'0';
        int need = t[i]-'0';
        if(got == 0 && need == 1) ++carry;
        else if(got == 1 && need == 0) {
            if(carry > 0) --carry;
            else ++carry;
        }
        res += carry;
    }
    if(carry == 0) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}