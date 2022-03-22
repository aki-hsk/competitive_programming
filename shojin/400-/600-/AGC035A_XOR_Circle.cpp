#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int N;
vector<int> A;
map<int, int> ma;

bool solve() {
    if(N % 3 != 0) return (ma[0] == N);
    vector<int> v;
    for(auto it:ma) v.push_back(it.first);
    if(v.size() == 1) return (ma[0] == N);
    else if(v.size() == 2) return (ma[0] == N/3);
    else if(v.size() == 3) {
        if((v[0]^v[1]^v[2]) != 0) return false;
        return (ma[v[0]] == N/3 && ma[v[1]] == N/3 && ma[v[2]] == N/3);
    }
    else return false;
}



int main() {
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++) cin >> A[i], ++ma[A[i]];
    cout << (solve() ? "Yes" : "No") << endl;
}
