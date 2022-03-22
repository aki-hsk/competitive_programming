#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    if(b > 0) return gcd(b, a%b);
    return a;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int g = a[0];
    int M = *max_element(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        g = gcd(g, a[i]);
    }
    if(M >= k && k % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}