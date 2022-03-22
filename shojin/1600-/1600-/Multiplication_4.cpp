#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

bool comp(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end(), comp);
    int minus = 0;
    for(int i=0; i<k; i++) {
        if(a[i] < 0) minus++;
    }

    mint ans = 1;
    for(int i=0; i<k; i++) ans *= a[i];
    if(minus % 2 == 0) {
        cout << ans.val() << endl;
        return 0;
    }

    int cur_p = -1, cur_n = -1;
    for(int i=k-1; i>=0; i--) {
        if(a[i] > 0 && cur_p == -1) cur_p = i;
        if(a[i] < 0 && cur_n == -1) cur_n = i;
    }
    int np = -1, nn = -1;
    for(int i=k; i<n; i++) {
        if(a[i] > 0 && np == -1) np = i;
        if(a[i] < 0 && nn == -1) nn = i;
    }

    long long m1 = -1, m2 = -1;
    // + -> -
    if(cur_p == -1 && np != -1) {
        ans /= a[cur_n];
        ans *= a[np];
        cout << ans.val() << endl;
        return 0;
    }
    if(cur_p != -1 && cur_n != -1 && nn != -1) {
        m1 = abs(a[cur_n] * a[nn]);
    }
    // - -> +
    if(cur_n != -1 && cur_p != -1 && np != -1) {
        m2 = abs(a[cur_p] * a[np]);
    }
    if(m1 == -1 && m2 == -1) {
        ans = 1;
        for(int i=0; i<k; i++) ans *= a[n-1-i];
        cout << ans.val() << endl;
        return 0;
    }
    else if(m1 > m2) {
        ans /= a[cur_p];
        ans *= a[nn];
    }
    else {
        ans /= a[cur_n];
        ans *= a[np];
    }
    cout << ans.val() << endl;
    return 0;
}