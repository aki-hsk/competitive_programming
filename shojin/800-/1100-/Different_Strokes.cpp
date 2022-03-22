#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://www.youtube.com/watch?v=x5x2Xg_gVWY

// まず二つのケースとかで考えてみる!!
// a1-b2 >= a2-b1
// a1+b1 >= a2+b2

int main() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    vector<pair<long long, int>> s(n);
    for(int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        s[i] = make_pair(a[i] + b[i], i);
    }

    long long ans = 0;
    sort(s.rbegin(), s.rend());
    for(int i=0; i<n; i++) {
        int j = s[i].second;
        if(i%2 == 0) ans += a[j];
        else ans -= b[j];
    }
    cout << ans << endl;
}