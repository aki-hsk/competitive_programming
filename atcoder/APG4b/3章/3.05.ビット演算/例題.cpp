#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    for(int tmp=0; tmp<(1<<N); tmp++) {
        int sum = 0;
        for(int i=0; i<N; i++) {
            if(tmp>>i&1) {
                sum += A[i];
            }
        }
        if(sum == K) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}