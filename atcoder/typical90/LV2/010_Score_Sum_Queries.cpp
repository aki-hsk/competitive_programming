#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p0(n), p1(n);
    for(int i=0; i<n; i++) {
        int c, p;
        cin >> c >> p;
        if(c == 1) p0[i] = p;
        else p1[i] = p;
    }
    vector<int> sum0(n+1), sum1(n+1);
    for(int i=0; i<n; i++) {
        sum0[i+1] = sum0[i] + p0[i];
        sum1[i+1] = sum1[i] + p1[i];
    }

    int q;
    cin >> q;
    for(int qi=0; qi<q; qi++) {
        int l, r;
        cin >> l >> r;
        printf("%d %d\n", sum0[r]-sum0[l-1], sum1[r]-sum1[l-1]);
    }
}