#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int K, X = 7, count=1;
    cin >> K;
    int N = X % K;
    if(K % 2 == 0 || K % 5 == 0) {
        cout << -1 << endl;
        return 0;
    }


    while(N != 0) {
        N = N * 10 + 7;
        N %= K;
        count++;
    }
    cout << count << endl;
}