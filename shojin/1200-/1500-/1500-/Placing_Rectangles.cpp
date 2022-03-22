#include<iostream>
using namespace std;

long long divCeil(long long a, long long b) { return (a+b-1)/b; }

bool f2(long long x, long long y, long long a, long long b) {
    long long w = divCeil(a, y) + divCeil(b, y);
    return w <= x;
}

bool f3(long long x, long long y, long long a, long long b, long long c) {
    long long w = divCeil(a, y);
    if(w >= x) return false;
    x -= w;
    return f2(x, y, b, c) || f2(y, x, b, c);
}

int main() {
    long long x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    for(int fi=0; fi<2; fi++) {
        for(int ri=0; ri<3; ri++) {
            if(f3(x, y, a, b, c)) {
                cout << "Yes" << endl;
                return 0;
            }
            swap(a, b);
            swap(b, c);
        }
        swap(x, y);
    }
    cout << "No" << endl;
    return 0;
}