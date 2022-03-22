#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main(){
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    vector<int> A;
    rep(i, N) A.push_back(i+1);
    // ベクターをキーにとると便利だよ
    map<vector<int>, int> M;

    do {
        M[A] = M.size();
    } while(next_permutation(all(A)));

    cout << abs(M[P] - M[Q]) << endl;
}