#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    for(int i=0; i<=N; i++) {
        int adult = 3*N - M + i;
        int old = M - 2*N - 2*i;
        if(adult >= 0 && old >= 0) {
            cout << adult << " " << old << " " << i << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}