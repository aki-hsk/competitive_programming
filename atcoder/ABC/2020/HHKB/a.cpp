#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

int main() {
    string S, T;
    cin >> S >> T;
    if(S == "Y") {
        transform(T.begin(), T.end(), T.begin(), ::toupper);
        cout << T << endl;
    }else {
        cout << T << endl;
    }
}