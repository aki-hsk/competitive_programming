#include<iostream>
using namespace std;

// https://drken1215.hatenablog.com/entry/2018/09/02/011000

int main() {
    long long n, k;
    cin >> n >> k;
    if(k % 2 == 0) {
        // n以下のkの倍数の個数
        long long a = n / k;
        // n以下のkで割ってk/2余る整数の個数
        long long b = (n + (k/2)) / k;

        cout << a * a * a + b * b * b << endl;
    }
    else {
        // n以下のkの倍数の個数
        long long a = n / k;
        cout << a * a * a << endl;
    }
}