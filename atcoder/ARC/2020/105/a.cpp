#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if(A == B+C+D || B == A+C+D || C == A+B+D || D == A+B+C || A+B == C+D || B+C == A+D || A+C == B+D) {
        cout << "Yes" << endl;
    }
    else {
        cout<< "No" << endl;
    }
}