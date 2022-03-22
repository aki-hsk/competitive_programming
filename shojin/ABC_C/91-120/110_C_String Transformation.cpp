#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    string S, T;
    cin >> S >> T;
    vector<int> start(26, -1);
    vector<int> goal(26, -1);

    for(int i=0; i<S.size(); i++) {
        int a = S[i] - 'a';
        int b = T[i] - 'a';
        if(start[a] != -1 || goal[b] != -1) {
            if(start[a] != b || goal[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }
        start[a] = b;
        goal[b] = a;
    }
    cout << "Yes" << endl;
    return 0;
}