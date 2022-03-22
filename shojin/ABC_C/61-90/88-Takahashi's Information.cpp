#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int c[3][3];
    int a[3], b[3];

    for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> c[i][j];
    a[0] = 0;
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(a[i] + b[j] != c[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}