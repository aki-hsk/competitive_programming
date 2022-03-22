#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n), s(n), f(n);
    rep(i, n-1) {
        cin >> c[i] >> s[i] >> f[i];
    }

    for(int i=0; i<n; i++) {
        int t = 0;
        for(int j=i; j<n-1; j++) {
            if(s[j] >= t) t = s[j];
            else if(t % f[j] == 0);
            else t = t + f[j] - (t % f[j]);
            t += c[j];
        }
        cout << t << endl;
    }
}