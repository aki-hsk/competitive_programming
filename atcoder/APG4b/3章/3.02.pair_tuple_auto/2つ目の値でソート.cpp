#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> p(N);

    //1つめの要素でソートされるので入力時に逆で受け取っておく
    for(int i=0; i<N; i++) cin >> p[i].second >> p[i].first;

    sort(p.begin(), p.end());
    for(int i=0; i<N; i++) {
        cout << p[i].second << " " << p[i].first << endl;
    }
}