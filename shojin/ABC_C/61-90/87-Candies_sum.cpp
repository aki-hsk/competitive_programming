#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    int A[2][N];

    for(int i=0; i<2; i++) for(int j=0; j<N; j++) cin >> A[i][j];

    int max_candy = 0, up_count = 0;

    for(int i=0; i<N; i++) {
        up_count += A[0][i];
        int count = up_count;
        for(int j=i; j<N; j++) {
            count += A[1][j];
        }
        max_candy = max(max_candy, count);
    }

    cout << max_candy << endl;
}