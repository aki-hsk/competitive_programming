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

    //upper_total, lower_totalの考え方が間違っている。
    //upper_total > lower_totalでは途中で枝分かれする場合が考えられていない

    ll upper_total = 0;
    ll lower_total = 0;

    for(int i=1; i<N; i++) upper_total += A[0][i];
    for(int i=0; i<N-1; i++) lower_total += A[1][i];

    ll ans = A[0][0] + A[1][N-1];
    for(int j=1; j<N; j++) {
        cout << lower_total << endl;
        cout << upper_total << endl;
        if(upper_total > lower_total) {
            ans += A[0][j];
            upper_total -= A[0][j];
            lower_total -= A[1][j-1];
        }

        else if(lower_total >= upper_total) {
            ans += lower_total;
            break;
        }
    }

    cout << ans << endl;
}