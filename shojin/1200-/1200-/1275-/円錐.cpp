#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const double PI=3.14159265358979323846;

double valume(double r, double h) {
    return PI * r * r * h / 3.0;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<double> p_sum(20005);
    vector<double> x(n), r(n), h(n);
    for(int i=0; i<n; i++) cin >> x[i] >> r[i] >> h[i];

    for(int i=20005; i>=0; i--) {
        for(int j=0; j<n; j++) {
            double v = valume(r[j], h[j]);
            if(x[j] >= i) v = 0;
            else if(x[j] <= i && i <= x[j] + h[j]) {
                double R = r[j] * (x[j] + h[j] - i) / h[j];
                v -= valume(R, x[j]+h[j]-i);
            }
            p_sum[i] += v;
        }
    }

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        printf("%.20f\n", p_sum[b]-p_sum[a]);
    }
}