#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> score(N);
    for(int i=0; i<N; i++) cin >> score[i];

    int start = 0;
    int last = K;

    for(int i=K; i<N; i++) {
        if(score[start] > score[last]) cout << "No" << endl;
        else cout << "Yes" << endl;
        start++;
        last++;
    }
}