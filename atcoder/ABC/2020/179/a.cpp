#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll mod=1000000007;

int main(){
    string S;
    cin >> S;

    if(S.back() == 's') {
        S += "es";
    }
    else {
        S += 's';
    }
    cout << S << endl;
}