#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    ll count = 0;

    for(int i=1; i<N; i++) {
        if(A[i-1] > A[i]) {
            count += (A[i-1]-A[i]);
            A[i] = A[i-1];
        }
    }
    cout << count << endl;
}