#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

const ll C = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> men(N, 0);
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        men[x]++;
    }

    ll count = 1;

    //奇数個
    if(N % 2 == 1 && men[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    if(N % 2 == 1) {
        for(int i=2; i<N; i += 2) {
            if(men[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
            else {
                count *= 2;
                count %= C;
            }
        }
        cout << count << endl;
        return 0;
    }

    //偶数個
    if(N % 2 == 0) {
        for(int i=1; i<N; i += 2) {
            if(men[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
            else {
                count *= 2;
                count %= C;
            }
        }
        cout << count << endl;
        return 0;
    }
}