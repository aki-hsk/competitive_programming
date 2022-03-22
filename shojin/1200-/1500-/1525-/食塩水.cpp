#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
// https://www.slideshare.net/chokudai/abc034
// https://procon-nenuon61.hatenablog.com/entry/2017/10/06/222847

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> w(n), p(n);
    for(int i=0; i<n; i++) cin >> w[i] >> p[i];

    // 目標とする %に対して容器がどれだけのメリットがあるかを考える！
    auto ok = [&](double mid) {
        vector<double> v;
        for(int i=0; i<n; i++) {
            v.push_back((p[i]-mid) * w[i]);
        }
        sort(v.rbegin(), v.rend());
        double m = accumulate(v.begin(), v.begin()+k, 0.0L);
        return m >= 0;
    };

    double left = 0, right = 100.0;
    for(int _=0; _<100; _++) {
        double mid = (left + right) / 2.0;
        if(ok(mid)) left = mid;
        else right = mid;
    }
    printf("%.20f\n", left);
    return 0;
}