#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    int count = 0;

    while(A >= B) {
        B *= 2;
        count++;
    }
    while(B >= C) {
        C *= 2;
        count++;
    }

    if(count <= K) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}