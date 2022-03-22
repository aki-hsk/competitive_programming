#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    bool flg = false;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if((y[i]-y[j])*(x[i]-x[k]) == (y[i]-y[k])*(x[i]-x[j])) {
                    flg = true;
                    break;
                }
            }
        }
    }
    cout << (flg ? "Yes" : "No") << endl;
}