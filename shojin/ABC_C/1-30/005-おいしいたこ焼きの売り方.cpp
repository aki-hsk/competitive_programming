#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int T, N;
    cin >> T >> N;
    vector<int> A(101);
    A[0] = 0;
    rep(i, N) {
        int a;
        cin >> a;
        A[a]++;
    }

    int M;
    cin >> M;
    vector<int> B(M);
    rep(i, M) cin >> B[i];


    bool flg;
    for(int i=0; i<M; i++) {
        flg = false;
        for(int j=max(B[i]-T, 0); j<=B[i]; j++) {
            if(A[j] > 0) {
                A[j]--;
                flg = true;
                break;
            }
        }
        if(!flg) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}

