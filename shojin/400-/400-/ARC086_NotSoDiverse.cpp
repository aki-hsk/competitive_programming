#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(200005);
    rep(i, N) {
        int a;
        cin >> a;
        A[a]++;
    }
    sort(all(A));
    reverse(all(A));

    for(int i=0; i<K; i++) N -= A[i];
    cout << N << endl;
}