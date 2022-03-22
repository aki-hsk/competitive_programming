#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> R(n);
    rep(i, n) cin >> R[i];
    sort(R.begin(), R.end());

    double rating = 0;
    for(int i=n-k; i<n; i++) {
        rating = (rating + R[i]) / 2.0;
    }
    printf("%.10f\n", rating);
}