#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    long long total = 0;
    for(int i=0; i<n; i++) total += a[i];

    double ans = (1LL<<55);
    double sum = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        double x = a[i]/2.0;
        double lost = (total + x * n);
        double compensation_total = sum + (x * 2.0 * (n-i));
        ans = min(ans, (lost - compensation_total)/n);
        sum += a[i];
    }
    printf("%.30f\n", ans);
}