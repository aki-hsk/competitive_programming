#include <bits/stdc++.h>
using namespace std;

int main() {
    double N, K;
    cin >> N >> K;

    double p = 0;
    for(int i=1; i<=N; i++) {
        int cnt = 0;
        int x = i;
        while(x < K) {
            x *= 2;
            cnt++;
        }
        p += 1/(pow(2, cnt) * N);
    }
    printf("%.12f\n", p);
}