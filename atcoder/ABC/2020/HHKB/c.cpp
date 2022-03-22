#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> x(200005, -1);

    int start = 0;
    for(int i=0; i<N; i++) {
        int p;
        cin >> p;
        x[p]++;
        for(int i=start; i<x.size(); i++) {
            if(x[i] == -1) {
                cout << i << endl;
                start = i;
                break;
            }
        }
    }
}