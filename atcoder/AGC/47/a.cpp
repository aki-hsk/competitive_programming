#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<long double> V(N);
    for(int i=0; i<N; i++) cin >> V[i];
    int count = 0;

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            long double mul = V[i] * V[j];
            //cout << "V[i]:" << V[i] << " V[j]:" << V[j] << " mul: "<< mul << endl;
            if(ceil(mul) == floor(mul)) {
                count++;
            }
        }
    }
    cout << count << endl;
}