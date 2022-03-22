#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7; //10の9乗

int main(){
    int X;
    cin >> X;

    for(int i=1; i<=X; i++) {
        if((i*(i+1))/2 >= X) {
            cout << i << endl;
            return 0;
        }
    }
}