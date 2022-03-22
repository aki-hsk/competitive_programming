#include<iostream>
#include<cmath>
using namespace std;

// https://qiita.com/ganyariya/items/1553ff2bf8d6d7789127
int main() {
    double p;
    cin >> p;

    auto f = [&](double x) {
        return x + p / pow(2, x/1.5);
    };

    double low = 0;
    double high = 1e2;

    int cnt = 500;
    while(cnt--) {
        double c1 = (low * 2 + high) / 3;
        double c2 = (low + high * 2) / 3;

        if(f(c1) > f(c2)) low = c1;
        else high = c2;
    }
    printf("%.20f\n", f(low));
}