#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();

    int use_a = 0, use_b = 0;
    for(int j=0; j<26; j++) {
        int xa = count(a.begin(), a.end(), 'A'+j);
        int xb = count(b.begin(), b.end(), 'A'+j);
        int xc = count(c.begin(), c.end(), 'A'+j);
        if(xc > xa + xb) {
            cout << "NO" << endl;
            return 0;
        }
        use_a += max(0, xc - xb);
        use_b += max(0, xc - xa);
    }
    if(use_a <= n/2 && use_b <= n/2) {
        cout << "YES" << endl;
        return 0;
    }
    else cout << "NO" << endl;
}