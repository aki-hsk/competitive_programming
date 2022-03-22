#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, count=0;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    for(int i=0; i<N; i++) {
        while(A[i] > 0) {
            for(int j=i; j<N; j++) {
                if(A[j] == 0) break;
                A[j]--;
            }
            count++;
        }
    }
    cout << count << endl;
}