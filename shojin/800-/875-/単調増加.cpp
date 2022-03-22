#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int r = 1;
    long long ans = 0;
    for(int l=0; l<n; l++) {
        if(r <= l) r = l+1;
        while(r < n && a[r-1] < a[r]) r++;
        ans += r-l;
    }
    cout << ans << endl;
}