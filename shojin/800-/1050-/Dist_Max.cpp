#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n), sum(n), sub(n);
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        sum[i] = x[i] + y[i];
        sub[i] = x[i] - y[i];
    }
    sort(sum.begin(), sum.end());
    sort(sub.begin(), sub.end());
    cout << max(sum.back()-sum[0], sub.back()-sub[0]) << endl;
}
