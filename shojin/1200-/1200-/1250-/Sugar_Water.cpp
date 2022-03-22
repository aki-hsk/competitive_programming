#include<iostream>
#include<set>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    set<int> su, wa;

    for(int i=0; i<=f; i++) {
        for(int j=0; j<=f; j++) {
            int x = 100*i*a+100*j*b;
            if(x <= f) wa.insert(x);
        }
    }
    for(int i=0; i<=f; i++) {
        for(int j=0; j<=f; j++) {
            int y = i*c+j*d;
            if(y <= f) su.insert(y);
        }
    }

    double max_concentration = -1;
    int water = 0, sugar = 0;

    for(auto w:wa) {
        for(auto s:su) {
            if(w + s > f) continue;
            if(s * 100 > e * w) continue;
            double concentration = (double)s/(w+s);
            if(concentration > max_concentration) {
                water = w;
                sugar = s;
                max_concentration = concentration;
            }
        }
    }
    printf("%d %d\n", water + sugar, sugar);
}