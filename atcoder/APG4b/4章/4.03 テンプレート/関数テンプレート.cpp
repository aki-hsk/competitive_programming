#include<bits/stdc++.h>
using namespace std;

int square_int(int x) {
    return x * x;
}
double square_double(double x) {
    return x * x;
}

template <typename T>
T square(T x) {
    return x * x;
}

int main() {
    int a = 3;
    double b = 1.2;

    cout << square_int(a) << endl;
    cout << square_double(b) << endl;

    cout << square<int>(a) << endl;
    cout << square<double>(b) << endl;

    // テンプレート関数の省略
    // 型から類推が可能な場合は省略ができる
    cout << square(a) << endl;
    cout << square(b) << endl;
}