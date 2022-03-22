#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    if(t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity" << endl;
        return 0;
    }

    long long tot_a = t1*a1 + t2 * a2;
    long long tot_b = t1*b1 + t2 * b2;
    if(tot_a < tot_b) {
        swap(a1, b1);
        swap(a2, b2);
        swap(tot_a, tot_b);
    }
    if(a1 > b1) {
        cout << 0 << endl;
        return 0;
    }

    long long tot_div = tot_a - tot_b;
    long long t1_div = b1*t1-a1*t1;
    long long ans = 1;
    ans += (t1_div / tot_div) * 2;
    if(t1_div % tot_div == 0) ans--;
    cout << ans << endl;
}
// 1 1
// 4 5
// 7 1