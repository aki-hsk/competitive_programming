#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
    vector<int> v(3);
    rep(i, 3) cin >> v[i];
    if(N == v[0] || N == v[1] || N == v[2]) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i=0; i<100; i++) {
        if(N-3 != v[0] && N-3 != v[1] && N-3 != v[2]) N -= 3;
        else if (N-2 != v[0] && N-2 != v[1] && N-2 != v[2]) N -= 2;
        else if (N-1 != v[0] && N-1 != v[1] && N-1 != v[2]) N -= 1;
        else N = 10000;
    }

    if(N > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}