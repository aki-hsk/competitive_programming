#include<bits/stdc++.h>
using namespace std;

int N;
string S = "110", T;

long long solve() {
    long long const V = 10000000000LL;
    if(T == "0") return V;
    else if(T == "1") return V * 2;

    long long res = 0;
    for(int i=0; i<3; i++) {
        long long a = (T.size() + i + 2) / 3;
        long long add = V -a + 1;

        bool ok = true;
        for(int j=0; j<T.size(); ++j) {
            if(T[j] != S[(j+i)%3]) ok = false;
        }
        if(ok) res += add;
    }
    return res;
}


int main() {
    cin >> N >> T;
    cout << solve() << endl;
}