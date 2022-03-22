#include <bits/stdc++.h>
using namespace std;

int main() {
    double N, K;
    cin >> N >> K;
    cout << 1 + ceil((N-K)/(K-1));
}
